(this["webpackJsonpmy-chat-app"]=this["webpackJsonpmy-chat-app"]||[]).push([[0],{47:function(e,t,a){},95:function(e,t,a){"use strict";a.r(t);var s=a(0),c=a(16),n=a.n(c),r=a(13),l=(a(47),a(7)),i=a(9),o=a(97),u=a(98),d=a(1);var m=function(e){var t=Object(s.useState)(""),a=Object(i.a)(t,2),c=a[0],n=a[1],r=e.chatId,m=e.creds,j=function(e){e.preventDefault();var t=c.trim();t.length>0&&Object(l.n)(m,r,{text:t}),n("")};return Object(d.jsxs)("form",{className:"message-form",onSubmit:j,children:[Object(d.jsx)("input",{className:"message-input",placeholder:"Send a message...",value:c,onChange:function(t){n(t.target.value),Object(l.k)(e,r)},onSubmit:j}),Object(d.jsx)("label",{htmlFor:"upload-button",children:Object(d.jsx)("span",{className:"image-button",children:Object(d.jsx)(o.a,{className:"picture-icon"})})}),Object(d.jsx)("input",{type:"file",multiple:!1,id:"upload-button",style:{display:"none"},onChange:function(e){Object(l.n)(m,r,{files:e.target.files,text:""})}}),Object(d.jsx)("button",{type:"submit",className:"send-button",children:Object(d.jsx)(u.a,{className:"send-icon"})})]})};var j=function(e){var t,a=e.message;return(null===a||void 0===a||null===(t=a.attachments)||void 0===t?void 0:t.length)>0?Object(d.jsx)("img",{src:a.attachments[0].file,alt:"message-attachment",className:"message-image",style:{float:"right"}}):Object(d.jsx)("div",{className:"message",style:{float:"right",marginRight:"18px",color:"white",backgroundColor:"#3B2A50"},children:a.text})};var b=function(e){var t,a,s=e.lastMessage,c=e.message,n=!s||s.sender.username!==c.sender.username;return Object(d.jsxs)("div",{className:"message-row",children:[n&&Object(d.jsx)("div",{className:"message-avatar",style:{backgroundImage:"url(".concat(null===c||void 0===c||null===(t=c.sender)||void 0===t?void 0:t.avatar,")")}}),(null===c||void 0===c||null===(a=c.attachments)||void 0===a?void 0:a.length)>0?Object(d.jsx)("img",{src:c.attachments[0].file,alt:"message-attachment",className:"message-image",style:{marginLeft:n?"4px":"48px"}}):Object(d.jsx)("div",{className:"message",style:{float:"left",backgroundColor:"#CABCDC",marginLeft:n?"4px":"48px"},children:c.text})]})};var h=function(e){var t=e.chats,a=e.activeChat,s=e.userName,c=e.messages,n=t&&t[a],l=function(e,t){return n.people.map((function(a,s){var c;return a.last_read===e.id&&Object(d.jsx)("div",{className:"read-receipt",style:{float:t?"right":"left",backgroundImage:"url(".concat(null===a||void 0===a||null===(c=a.person)||void 0===c?void 0:c.avatar,")")}},"read_".concat(s))}))};return n?Object(d.jsxs)("div",{className:"chat-feed",children:[Object(d.jsxs)("div",{className:"chat-title-container",children:[Object(d.jsx)("div",{className:"chat-title",children:null===n||void 0===n?void 0:n.title}),Object(d.jsx)("div",{className:"chat-subtitle",children:n.people.map((function(e){return"".concat(e.person.username)}))})]}),function(){var e=Object.keys(c);return e.map((function(t,a){var n=c[t],r=0===a?null:e[a-1],i=s===n.sender.username;return Object(d.jsxs)("div",{style:{width:"100%"},children:[Object(d.jsx)("div",{className:"message-block",children:i?Object(d.jsx)(j,{message:n}):Object(d.jsx)(b,{message:n,lastMessage:n[r]})}),Object(d.jsx)("div",{className:"read-receipts",style:{marginRight:i?"18px":"0px",marginLeft:i?"0px":"68px"},children:l(n,i)})]},"mesg_".concat(a))}))}(),Object(d.jsx)("div",{style:{height:"100px"}}),Object(d.jsx)("div",{className:"message-form-container",children:Object(d.jsx)(m,Object(r.a)(Object(r.a)({},e),{},{chatId:a}))})]}):"Loading..."},p=a(23),g=a.n(p),v=a(41),x=a(4),O=a.n(x);var f=function(){var e=Object(s.useState)(""),t=Object(i.a)(e,2),a=t[0],c=t[1],n=Object(s.useState)(""),r=Object(i.a)(n,2),l=r[0],o=r[1],u=Object(s.useState)(""),m=Object(i.a)(u,2),j=m[0],b=m[1],h=function(){var e=Object(v.a)(g.a.mark((function e(t){var s;return g.a.wrap((function(e){for(;;)switch(e.prev=e.next){case 0:return t.preventDefault(),s={"Project-ID":"97c7c307-bd28-4c78-80a4-6b98544ea175","User-Name":a,"User-Secret":l},e.prev=2,e.next=5,O.a.get("https://api.chatengine.io/chats",{headers:s});case 5:localStorage.setItem("username",a),localStorage.setItem("password",l),window.location.reload(),e.next=13;break;case 10:e.prev=10,e.t0=e.catch(2),b("oops, incorrect credentials");case 13:case"end":return e.stop()}}),e,null,[[2,10]])})));return function(t){return e.apply(this,arguments)}}();return Object(d.jsx)("div",{className:"wrapper",children:Object(d.jsxs)("div",{className:"form",children:[Object(d.jsx)("h1",{className:"title",children:"Chat Application"}),Object(d.jsxs)("form",{onSubmit:h,children:[Object(d.jsx)("input",{type:"text",value:a,onChange:function(e){return c(e.target.value)},className:"input",placeholder:"Username",required:!0}),Object(d.jsx)("input",{type:"password",value:l,onChange:function(e){return o(e.target.value)},className:"input",placeholder:"Password",required:!0}),Object(d.jsx)("div",{align:"center",children:Object(d.jsx)("button",{type:"submit",className:"button",children:Object(d.jsx)("span",{children:"Start Chatting"})})}),Object(d.jsx)("h2",{className:"error",children:j})]})]})})};var N=function(){return localStorage.getItem("username")?Object(d.jsx)(l.c,{height:"100vh",projectID:"97c7c307-bd28-4c78-80a4-6b98544ea175",userName:localStorage.getItem("username"),userSecret:localStorage.getItem("password"),renderChatFeed:function(e){return Object(d.jsx)(h,Object(r.a)({},e))}}):Object(d.jsx)(f,{})};n.a.render(Object(d.jsx)(N,{}),document.getElementById("root"))}},[[95,1,2]]]);
//# sourceMappingURL=main.b2ea4cb1.chunk.js.map