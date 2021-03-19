import React from 'react'
import './App.scss';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom'
import NavbarComponent from './components/NavbarComponent/NavbarComponent'
import FooterComponent from './components/FooterComponent/FooterComponent'
import HomePage from './components/HomePage/HomePage';
import Projects from './components/Projects/Projects';
import Contact from './components/Contact/Contact';
import { Container } from 'react-bootstrap';
import SimpleReactLightbox from "simple-react-lightbox";


function App() {
    return (
        <div className="App">
            <SimpleReactLightbox>
                <Router>
                    <Container>
                        <NavbarComponent />
                        <br />
                        <div className="glass">
                            <br />
                            <Switch >
                                <Container>
                                    <Route path="/" exact component={HomePage} />
                                    <Route path="/projects" exact component={Projects} />
                                    <Route path="/contact" exact component={Contact} />
                                </Container>
                            </Switch>
                        </div>
                    </Container>
                    <FooterComponent />
                </Router>
            </SimpleReactLightbox>
            <span className="circle2"></span>
            <span className="circle1"></span>
        </div>
    );
}


export default App;
