import React, { useState, useEffect } from 'react'
import { Link } from 'react-router-dom'

function Shop() {
    useEffect(() => {
        fetchItems();
    }, [])

    const [items, setItems] = useState([]);

    const fetchItems = async () => {
        const data = await fetch('https://picsum.photos/v2/list')

        const items = await data.json();
        items.map(item => (
            console.log('url : ', JSON.stringify(item.url))
        ))
        setItems(items)
    }
    return (
        <div>
            {items.map(item => (
                <h1>
                    <Link to={`/shop/${item.id}`} >{item.author}</Link>
                </h1>
            ))}
        </div>
    )
}

export default Shop
