(this["webpackJsonpmy-todo-app"]=this["webpackJsonpmy-todo-app"]||[]).push([[0],{13:function(t,e,o){},15:function(t,e,o){"use strict";o.r(e);var s=o(1),c=o(7),n=o.n(c),a=o(3),l=(o(13),o(8)),i=o(0);function d(t){var e=t.inputText,o=t.setInputText,s=t.todos,c=t.setTodos,n=t.setStatus;return Object(i.jsxs)("form",{children:[Object(i.jsx)("input",{value:e,onChange:function(t){o(t.target.value)},type:"text",className:"todo-input"}),Object(i.jsx)("button",{onClick:function(t){t.preventDefault(),c([].concat(Object(l.a)(s),[{text:e,completed:!1,id:1e3*Math.random()}])),o("")},className:"todo-button",type:"submit",children:Object(i.jsx)("i",{className:"fas fa-plus-square"})}),Object(i.jsx)("div",{className:"select",children:Object(i.jsxs)("select",{onChange:function(t){n(t.target.value)},name:"todos",className:"filter-todo",children:[Object(i.jsx)("option",{value:"all",children:"All"}),Object(i.jsx)("option",{value:"completed",children:"Completed"}),Object(i.jsx)("option",{value:"uncompleted",children:"Uncompleted"})]})})]})}var r=o(6);function u(t){var e=t.text,o=t.todo,s=t.todos,c=t.setTodos;return Object(i.jsxs)("div",{className:"todo",children:[Object(i.jsx)("li",{className:"todo-item  ".concat(o.completed?"completed":""),children:e}),Object(i.jsx)("button",{onClick:function(){c(s.map((function(t){return t.id===o.id?Object(r.a)(Object(r.a)({},t),{},{completed:!t.completed}):t})))},className:"complete-btn",children:Object(i.jsx)("i",{className:"fas fa-check"})}),Object(i.jsx)("button",{onClick:function(){c(s.filter((function(t){return t.id!==o.id})))},className:"trash-btn",children:Object(i.jsx)("i",{className:"fas fa-trash"})})]})}function j(t){var e=t.todos,o=t.setTodos,s=t.status,c=t.filteredTodos;return Object(i.jsx)("div",{className:"todo-container",children:Object(i.jsx)("ul",{className:"todo-list",children:c.map((function(t){return Object(i.jsx)(u,{status:s,todo:t,todos:e,setTodos:o,text:t.text},t.id)}))})})}function b(){var t=Object(s.useState)(""),e=Object(a.a)(t,2),o=e[0],c=e[1],n=Object(s.useState)([]),l=Object(a.a)(n,2),r=l[0],u=l[1],b=Object(s.useState)("all"),f=Object(a.a)(b,2),m=f[0],p=f[1],O=Object(s.useState)([]),x=Object(a.a)(O,2),h=x[0],v=x[1];return Object(s.useEffect)((function(){!function(){if(null===localStorage.getItem("todos"))localStorage.setItem("todos",JSON.stringify([]));else{var t=JSON.parse(localStorage.getItem("todos"));u(t)}}()}),[]),Object(s.useEffect)((function(){!function(){switch(m){case"completed":v(r.filter((function(t){return!0===t.completed})));break;case"uncompleted":v(r.filter((function(t){return!1===t.completed})));break;default:v(r)}}(),localStorage.setItem("todos",JSON.stringify(r))}),[r,m]),Object(i.jsxs)("div",{className:"App",children:[Object(i.jsx)("header",{children:"Sefa's Todo List "}),Object(i.jsx)(d,{inputText:o,todos:r,setTodos:u,setInputText:c,setStatus:p}),Object(i.jsx)(j,{filteredTodos:h,status:m,todos:r,setTodos:u})]})}n.a.render(Object(i.jsx)(b,{}),document.getElementById("root"))}},[[15,1,2]]]);
//# sourceMappingURL=main.601268b1.chunk.js.map