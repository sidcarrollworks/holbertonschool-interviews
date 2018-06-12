#!/usr/bin/python3
'''get info from api'''
import json, requests

if __name__ == "__main__":
    new_dict ={}
    url = "https://jsonplaceholder.typicode.com/"

    users = requests.get(url + "users/").json()
    for user in users:
        userId = user["id"]
        tasks = requests.get(url + "todos?userId={}".format(userId)).json()
        for each in tasks:
            each.pop("userId", None)
            each.pop("id", None)
            task_name = each.pop("title", None)
            completed = each.pop("completed", None)
            each["username"] = user["username"]
            each["task"] = task_name
            each["completed"] = completed
        new_dict[str(userId)] = tasks

    with open('todo_all_employees.json', 'w') as f:
        json.dump(new_dict, f)