import React, { useEffect, useState } from 'react'
import Nav from './Nav'

function ItemDetail({ match }) {

    useEffect(() => {
        fetchItem()
        console.log('object')
        console.log(match)
    }, [])


    const [item, setItem] = useState('')
    const fetchItem = async () => {
        const item = await fetch(`https://picsum.photos/id/${match.params.id}/200/300.jpg`)
        console.log(item)
        setItem(item.url)
    }

    return (
        <div>
            <h1>sss</h1>
            <img src={item} alt="sd" />
        </div>
    )
}

export default ItemDetail
