import React, { useState } from 'react'
import Characters from './Characters';
import Others from './Others';
import TabsComponent from './TabsComponent';

function Projects() {

    const [projectMod, setProjectMod] = useState(true);
    return (
        <div>
            <h1 style={{ marginBottom: '2rem', textAlign: 'center' }}>My Projects</h1>
            <br />
            <TabsComponent setProjectMod={setProjectMod} />
            <br />
            {
                projectMod ?
                    <Characters />
                    :
                    <Others />
            }
        </div>
    )
}

export default Projects
