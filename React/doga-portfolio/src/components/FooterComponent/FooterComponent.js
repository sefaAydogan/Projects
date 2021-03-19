import React from 'react'

function FooterComponent() {
    const footerStyle = {
        height: "10vh",
        background: "#658ec6c2",
        textAlign: "Center",
        zIndex: "3"
    }
    return (
        <div style={footerStyle}>
            <footer>
                <h1 style={{ color: "white" }}>This Project is not Finished Yet</h1>
            </footer>
        </div>

    )
}

export default FooterComponent
