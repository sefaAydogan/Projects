import React, { useState } from 'react'
import { Tab, Tabs } from 'react-bootstrap';

function TabsComponent({ setProjectMod }) {
    const [key, setKey] = useState('character');
    return (
        <div>
            <Tabs
                id="controlled-tab-example"
                activeKey={key}
                onSelect={(k) => {
                    setProjectMod(prev => !prev)
                    return setKey(k)
                }}
            >
                <Tab eventKey="character" title="Characters">
                    <span style={{ fontWeight: "bold" }}> My Character Designs </span>
                </Tab>
                <Tab eventKey="others" title="Others">
                    <span style={{ fontWeight: "bold" }}> Other 3D  that I have done </span>
                </Tab>
            </Tabs>
        </div>
    )
}

export default TabsComponent
