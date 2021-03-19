import React from 'react'
//import { Link } from 'react-router-dom'
import { Nav, Navbar } from 'react-bootstrap'
import './Navbar.scss'

function NavbarComponent() {
    const NavbarStyle = {
        background: "#658ec6c2",
        borderRadius: "1rem",
        zIndex: "3"
    }
    const NavBrandStyle = {
        color: "white",
        margin: "2rem 1rem 2rem 2rem",
        fontWeight: "bold"
    }
    const NavLinkStyle = {
        color: "white",
        margin: "1rem 1rem 1rem 1rem",
        letterSpacing: "5px",
        fontSize: "20px",
        fontWeight: "bold"
    }

    return (
        <Navbar style={NavbarStyle} collapseOnSelect expand="lg" variant="dark" >
            <Navbar.Brand style={NavBrandStyle} href="/">İlke Doğa Eygi</Navbar.Brand>
            <Navbar.Toggle aria-controls="responsive-navbar-nav" />
            <Navbar.Collapse id="responsive-navbar-nav" className="justify-content-end">
                <Nav style={{ marginRight: "2rem" }}>
                    <Nav.Link style={NavLinkStyle} href="/">Home Page</Nav.Link>
                    <Nav.Link style={NavLinkStyle} href="/projects">Projects</Nav.Link>
                    <Nav.Link style={NavLinkStyle} href="/contact">Contact</Nav.Link>
                </Nav>
            </Navbar.Collapse>
        </Navbar >
    )
}

export default NavbarComponent
