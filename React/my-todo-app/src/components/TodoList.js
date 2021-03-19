import React from 'react'
import Todo from "./Todo"

export default function TodoList(props) {

    const { todos, setTodos, status, filteredTodos } = props


    return (
        <div className="todo-container">
            <ul className="todo-list">
                {filteredTodos.map(todo => (
                    <Todo
                        status={status}
                        todo={todo}
                        todos={todos}
                        setTodos={setTodos}
                        text={todo.text}
                        key={todo.id} />
                ))}
            </ul>
        </div>
    )
}
