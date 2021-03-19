import React, { useState } from 'react'
import './App.css'
import { ChatEngine } from 'react-chat-engine';
import ChatFeed from './components/ChatFeed'
import LoginForm from './components/LoginForm';
function App() {

    if (!localStorage.getItem('username')) {
        return <LoginForm />
    }

    return (
        <ChatEngine
            height="100vh"
            projectID="97c7c307-bd28-4c78-80a4-6b98544ea175"
            userName={localStorage.getItem('username')}
            userSecret={localStorage.getItem('password')}
            renderChatFeed={(chatAppProps) => <ChatFeed {...chatAppProps} />}
        />
    )
}

export default App
