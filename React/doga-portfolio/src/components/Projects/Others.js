import React from 'react'
import { Col, Container, Image, Row } from 'react-bootstrap'

import { SRLWrapper } from "simple-react-lightbox";
import othersData from './othersData';

function Others() {
    return (
        <Container>
            <SRLWrapper>
                <div className="card">
                    <Row className="justify-content-md-center">
                        {
                            othersData.map(other => {
                                return (
                                    <Col style={{ marginBottom: "2rem" }} key={other.id} xs={12} md={4}>
                                        <Image src={other.url} rounded fluid />
                                    </Col>
                                )
                            }
                            )
                        }
                    </Row>
                </div>
            </SRLWrapper>
        </Container>
    )
}

export default Others
