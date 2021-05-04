package main

import (
	"fmt"
	"database/sql"
	_ "github.com/go-sql-driver/mysql"
)

func main(){

	db, err := sql.Open("mysql", "root:@tcp(locallhost:3306)/test",)

	if err != nil{
		panic(err.Error())
	}

	defer db.close()

	fmt.Println("CONNECTED!")
}

