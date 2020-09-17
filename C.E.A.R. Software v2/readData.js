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
var rootRef = firebase.database().ref().child("Users");


rootRef.on("child_added", snap => {
  var name = snap.child("Name").val();
  var age = snap.child("Age").val();

  $("#table_body").append("<tr><td>" + name + "</td></td>" + age + "</td></tr>")
});
