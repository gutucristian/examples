Shortcuts

`v-on` prefix in event bindings can be replaced with `@`

Example: `<input type="button" v-on:click="foo">` can also be written as `<input type="button" @click="foo">`

`v-bind` prefix in attribute bindings can be completely omitted

Example: Example: `<input type="button" v-bind:value="bar">` can also be written as `<input type="button" :value="bar">`

Vue instance options

`el`: container where to inject app into to DOM

`data`: app data (or state) to be used

`methods`: methods of the vue instance

`computed`: dependent properties (used when calling a vue function in the template). This prevents the function from running needlessly if the data that it depends / uses is not modified in the app state (i.e., the vue instance `data` property).

`watch`: execute code upon data changes. Name of variable in `watch` option must be the same as the variable it is "watching" from `data`. **Note**: much of what can be accoplished with `computed` can be done with `watch`, but using `computed` is recommended because of its caching mechanism. Also, functions in computed must be synchronous (e.g., no network requests).

Miscellaneous

- There can be multiple Vue instances in an app each controlling different things. E.g., we could use Vue to embed a reactive calendar widget in an older project (e.g., one that uses JSPs).
- We can access Vue instance data and methods from outside the instance itself
- There is a possibility to call methods and data from one Vue instance to another it is **recommended not to do this**

When we create a new Vue instance, Vue requires an "options" object which we pass to its constructor. Behind the scenes, Vue "copies" this object and uses its data and methods as native properties on the Vue instance itself. It also sets up a "watcher" layer which watches each of the properties passed in the object so that it knows when they change. This is needed so that Vue knows when to update the app's state and possibly re-render the DOM. In the end, the Vue instance is a vanilla JavaScript object so we add properties to it even after we create the instance. **However** the instance will not recognize it and react to any references made to this new property because it **only creates the** previously mentioned **"watchers" once** -- when we pass the options object to the Vue instance constructor, any other property will be there, but it won't be under this "watcher" layer and won't have any getter and setters... thus rendering it unusable.

`ref` is an attribute provided by Vue that we can place on any HTML element 