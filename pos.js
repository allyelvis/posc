name: CI/CD Pipeline
 
on:
  push:
    branches:
      - main
 
jobs:
  build:
    runs-on: ubuntu-latest
 
    steps:
      - name: Checkout repository
        uses: actions/checkout@v2
 
      - name: Set up Node.js
        uses: actions/setup-node@v2
        with:
          node-version: 14
 
      - name: Install dependencies
        run: npm install
 
      - name: Build
        run: npm run build
 
      - name: Test
        run: npm run test
 
      - name: Deploy to MySQL database
        run: |
          mysql -h mysql-28d68f05-allyelvis6569-cc54.a.aivencloud.com -P 12076 -u avnadmin -pAVNS_-Mo-rjrZh4fXnpMqfPO defaultdb < database.sql
 
      - name: Deploy to API server
        run: |
          curl -X POST -H "Content-Type: application/json" -d '{"database": "defaultdb", "host": "mysql", "port": 12076, "user": "avnadmin", "password": "AVNS_-Mo-rjrZh4fXnpMqfPO"}' https://api.example.com/integration
 
      - name: Deploy to POS system
        run: |
          curl -X POST -H "Content-Type: application/json" -d '{"database": "defaultdb", "host": "mysql", "port": 12076, "user": "avnadmin", "password": "AVNS_-Mo-rjrZh4fXnpMqfPO"}' https://pos.example.com/integration
