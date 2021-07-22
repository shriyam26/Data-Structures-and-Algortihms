Synchronous operations in JavaScript entails having each step of an operation waits for the previous step to execute completely. This means no matter how long a previous process takes, subsquent process won't kick off until the former is completed. Asynchronous operations, on the other hand, defers operations. Any process that takes a lot of time to process is usually run alongside other synchronous operation and completes in the future


The setTimeout function makes the operation asynchronous by deferring plant watering to occur after 3 seconds. The whole operation doesn’t pause for 3 seconds so it can log “Water plant”. Rather, the system goes ahead to apply fertilizers and then water plant after 3 seconds.


JavaScript Functions are first-class objects in and as such can functions have the ability to:

Be assigned to variables (and treated as a value)
Have other functions in them
Return other functions to be called later


Callback Fucntions =>
When a function simply accepts another function as an argument, this contained function is known as a callback function.

setInterval(function() {
  console.log('hello!');
}, 1000);

setInterval accepts a callback function as its first parameter and also a time interval. Another example using .map();

const list    = ['man', 'woman', 'child']

// create a new array
// loop over the array and map the data to new content
const newList = list.map(function(val) {
  return val + " kind";
});

// newList = ['man kind', 'woman kind', 'child kind']



function greeting(name) {
  console.log(`Hello ${name}, welcome to Scotch!`);
}
The above function is assigned a name greeting and has an argument of name. We're also using an ES6 template string. Let’s use this function as a callback function.

function introduction(firstName, lastName, callback) {
  const fullName = `${firstName} ${lastName}`;

  callback(fullName);
}

introduction('Chris','Nwamba', greeting); // Hello Chris Nwamba, welcome to Scotch!

Notice the usage of the callback? The succeeding brackets, () after the function are not used when passing the function as a parameter.

Note: The callback function is not run unless called by its containing function, it is called back. Hence, the term call back function


Callback functions are useful for short asynchronous operations. When working with large sets, this is not considered best practice. Because of this challenge, Promises were introduced to simplify deferred activities.

Promises =>

A promise is used to handle the asynchronous result of an operation. JavaScript is designed to not wait for an asynchrnous block of code to completely execute before other synchronous parts of the code can run. For instance, when making API requests to servers, we have no idea if these servers are offline or online, or how long it takes to process the server request.

With Promises, we can defer execution of a code block until an async request is completed. This way, other operations can keep running without interruption.

Promises have three states:

Pending: This is the initial state of the Promise before an operation begins
Fulfilled: This means the specified operation was completed
Rejected: The operation did not complete; an error value is usually thrown


Promises is created using new keyword and contains two arguments, resolve and reject. Resolve when the promise is fulfilled and reject when error is thrown.
Promises also occur in chaining.

Async and Await =>

An async function is a modification to the syntax used in writing promises. An async function is a modification to the syntax used in writing promisesAn async function returns a promise -- if the function returns a value, the promise will be resolved with the value, but if the async function throws an error, the promise is rejected with that value. Let’s see an async function:

async function myRide() {
  return '2017 Dodge Charger';
}
and a different function that does the same thing but in promise format:

function yourRide() {
  return Promise.resolve('2017 Dodge Charger');
}
From the above statements, myRide() and yourRide() are equal and will both resolve to 2017 Dodge Charger. Also when a promise is rejected, an async function is represented like this:

function foo() {
  return Promise.reject(25)
}

// is equal to
async function() {
  throw 25;
}

Await =>
Await is only used with an async function. The await keyword is used in an async function to ensure that all promises returned in the async function are synchronized, ie. they wait for each other. Await eliminates the use of callbacks in .then() and .catch(). In using async and await, async is prepended when returning a promise, await is prepended when calling a promise. try and catch are also used to get the rejection value of an async function. Let's see this with our date example:

async function myDate() {
  try {

    let dateDetails = await date;
    let message     = await orderUber(dateDetails);
    console.log(message);

  } catch(error) {
    console.log(error.message);
  }
}
Lastly we call our async function:

(async () => { 
  await myDate();
})();

