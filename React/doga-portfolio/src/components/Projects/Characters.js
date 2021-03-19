import React from 'react'
import { Col, Container, Image, Row } from 'react-bootstrap'
import { SRLWrapper } from "simple-react-lightbox";
import charactersData from "./charactersData";

function Characters() {

    return (
        <div>
            <Container>
                <SRLWrapper>
                    <div className="card">
                        <Row className="justify-content-md-center" xs={1} md={3} lg={3}>
                            {
                                charactersData.map(character => (
                                    <Col style={{ marginBottom: "2rem" }} key={character.id} xs={12} md={4}>
                                        <Image src={character.url} rounded fluid />
                                    </Col>
                                ))
                            }
                        </Row>
                    </div>
                </SRLWrapper>
            </Container>
        </div>
    )
}

export default Characters
