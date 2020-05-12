The `watch` vue instance option allows us to "watch" some variable in the app `data` object (i.e., app's state) and execute some code when the variable changes.

This is an alternative to the `computed` vue instance option which only re-runs a function if it embeds some variable in the vue instance `data` that is subsequently changed.

**Note**: unlike in the `watch` instance option, functions defined in the `computed` instance option must be synchronous.

Performance comparison: using `computed` is more performant because it uses a caching mechanism.