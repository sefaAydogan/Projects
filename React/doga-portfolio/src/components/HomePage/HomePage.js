import React from 'react'
import { Col, Container, Image, Row } from 'react-bootstrap'
import HomePagePhoto from '../Projects/Designs/HomePageTitle.png'
import Bar from '../Projects/Designs/Bar.png'
import RoomWithStairs from '../Projects/Designs/RoomWithStairs.png'
import IceCreamShop from '../Projects/Designs/IceCreamShop.png'
import PhotoshopLogo from './Ps_Logo.jpg'
import BlenderLogo from './Blender-Logo.png'
import Doya from './doya.png'
import IllustratorLogo from './Adobe-Illustrator-Logo.jpg'
import { SRLWrapper } from 'simple-react-lightbox'
function HomePage() {
    return (
        <div className="home-page">
            <Container>
                <Row>
                    <Col md={12} style={{ textAlign: "center", marginBottom: "2rem", marginTop: "1rem" }}>
                        <Image src={HomePagePhoto} width="80%" rounded fluid />
                    </Col>
                    <Col md={4}>
                        <Col md={12} style={{ textAlign: "center", marginTop: "2rem" }}>
                            <Col md={12} style={{ textAlign: "center", marginTop: "2rem" }}>
                                <Image src={Doya} width="150px" rounded fluid />
                            </Col>
                            <Col md={12} style={{ textAlign: "center" }}>
                                <h2>İlke Doğa Eygi</h2>
                            </Col>
                            <Col md={12} style={{ textAlign: "center" }}>
                                <h2>3D Artist / Designer</h2>
                            </Col>
                        </Col>
                    </Col>
                    <Col md={8} xs={12}>
                        <div className="card">
                            <Row>
                                <Col md={12} xs={12}>
                                    <h2 class="" style={{ textAlign: "center", marginBottom: "10px" }} >Who am I!</h2>
                                    <p>My name is Doğa. Generally, I do 3D models in a self-taught and self-motivated manner. At
                                    the same time, I am dealing with graphic design studies in line with the graphic courses
                                I took during my university education. In my works, I generally use programs such as <a
                                            href="https://www.blender.org" style={{ textDecoration: "none" }}>Blender</a>, <a
                                                href="https://www.adobe.com/tr/products/illustrator.html"
                                                style={{ textDecoration: "none" }}>Adobe Illustrator </a>
                                and <a href="https://www.adobe.com/tr/products/photoshop.html"
                                            style={{ textDecoration: "none" }}>Adobe Photoshop</a>. I spend most of my free time
                                doing 3d models based on the objects I see on the internet and around me. It has become
                                a hobby for me. I can't even imagine myself working in a job other than this one in the
                                future.
                            </p>
                                </Col>
                            </Row>
                        </div>
                    </Col>

                    <Col md={5} xs={12}>
                        <div className="card">
                            <Row className="justify-content-md-center">
                                <Col md={12} xs={12}>
                                    <h2 style={{ textAlign: "center", marginBottom: "2rem" }} >The programs I use</h2>
                                </Col>
                            </Row>
                            <Row className="justify-content-md-center">
                                <Col md={4} xs={12}>
                                    <Col md={12} xs={12}>
                                        <Image src={PhotoshopLogo} style={{ marginBottom: "1rem" }} width="100px" rounded fluid />
                                    </Col>
                                    <Col md={12} xs={12}>
                                        <h3 style={{ marginBottom: "1rem" }} >Adobe Photoshop</h3>
                                    </Col>
                                </Col>
                                <Col md={4} xs={12}>
                                    <Col md={12} xs={12}>
                                        <Image src={IllustratorLogo} style={{ marginBottom: "1rem" }} width="100px" rounded fluid />
                                    </Col>
                                    <Col md={12} xs={12}>
                                        <h3 style={{ marginBottom: "1rem" }} >Adobe Illustrator</h3>
                                    </Col>
                                </Col>
                                <Col md={4} xs={12}>
                                    <Col md={12} xs={12}>
                                        <Image src={BlenderLogo} style={{ marginBottom: "1rem" }} width="100px" rounded fluid />
                                    </Col>
                                    <Col md={12} xs={12}>
                                        <h3 style={{ marginBottom: "1rem" }} >Blender</h3>
                                    </Col>
                                </Col>
                            </Row>
                        </div>
                    </Col>
                    <Col md={7}>
                        <div className="card">
                            <Row className="justify-content-md-center">
                                <Col md={12} xs={12}>
                                    <h2 style={{ textAlign: "center", marginBottom: "2rem" }} >Highlights</h2>
                                </Col>
                            </Row>
                            <SRLWrapper>
                                <Row>
                                    <Col md={4} xs={12}>
                                        <Image src={Bar} style={{ marginBottom: "1rem" }} rounded fluid />
                                    </Col>
                                    <Col md={4} xs={12}>
                                        <Image src={RoomWithStairs} style={{ marginBottom: "1rem" }} rounded fluid />
                                    </Col>
                                    <Col md={4} xs={12}>
                                        <Image src={IceCreamShop} style={{ marginBottom: "1rem" }} rounded fluid />
                                    </Col>
                                </Row>
                            </SRLWrapper>
                        </div>
                    </Col>
                </Row>






            </Container>
        </div >
    )
}

export default HomePage
