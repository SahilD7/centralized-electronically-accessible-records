// Your web app's Firebase configuration
var firebaseConfig = {
    apiKey: "AIzaSyCCp0UY6bH4zFOFm05xHb2oCUyXxbq1f4g",
    authDomain: "test-af35a.firebaseapp.com",
    databaseURL: "https://test-af35a.firebaseio.com",
    projectId: "test-af35a",
    storageBucket: "test-af35a.appspot.com",
    messagingSenderId: "502940882319",
    appId: "1:502940882319:web:4dc9ca44298dae926227fa",
    measurementId: "G-9Y8RX269RQ"
};
// Initialize Firebase
firebase.initializeApp(firebaseConfig);
//firebase.analytics();


var signUpBtn = document.getElementById('signUpBtn');
var signInBtn = document.getElementById('signInBtn');

signUpBtn.addEventListener('click', function() {
  var emailField = document.getElementById('email').value;
  var passwordField = document.getElementById('password').value;

  firebase.auth().createUserWithEmailAndPassword(emailField, passwordField).then(function(){
      alert("User Created");
  }).catch(function(error){
      if(error != null){
        console.log(error.message);
        return;
    }
  });

});

signInBtn.addEventListener('click', function() {
  var emailField = document.getElementById('email').value;
  var passwordField = document.getElementById('password').value;
  firebase.auth().signInWithEmailAndPassword(emailField, passwordField).then(function(){
      alert("Successfully Signed In!")
      document.location.href = "Options.html";
  }).catch(function(error){
      if(error != null){
        console.log(error.message);
        return;
      }
  });

});
