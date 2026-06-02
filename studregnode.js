var express = require('express');
var app = express();
var path = require('path');

app.use(express.static(__dirname));

app.get('/studreg.html', function(req, res) {
    res.sendFile(path.join(__dirname, 'studreg.html'));
});

app.listen(8081, function() {
    console.log("Server running on port 8081");
});
