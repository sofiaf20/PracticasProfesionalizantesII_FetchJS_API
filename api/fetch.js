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
fetch('http://192.168.142.128/api/main.bin', requestOptions)
.then(response => response.text())
.then(result => console.log(result))
.catch(error => console.log('error', error))