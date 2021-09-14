var myHeaders = new Headers();
myHeaders.append("Content-Type", "application/json");

var raw = JSON.stringify({
"service": "TestService",
"action": "read"
});

var requestOptions = {
    method: 'POST',
    headers: myHeaders,
    body: raw,
    redirect: 'follow'
};
fetch('api-cpp-sugar-free-1.0\main', requestOptions)
.then(response => response.text())
.then(result => console.log(result))
.catch(error => console.log('error', error))