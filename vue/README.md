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

- There can be multiple Vue instances in an app
- We can access Vue instance data and methods from outside the instance itself
