#define HOOK_DEF(name, retval, ...) \
retval (*name ## _def)(__VA_ARGS__) = NULL; \
retval hook_ ## name(__VA_ARGS__) 

#define INIT_HOOK(libhandle, name) \
long addr_ ## name = (long)dlsym(libhandle, #name); \
if (!addr_ ## name) \
{ \
    err("Could not dlsym " #name ); \
    return; \
} \
registerInlineHook((uint32_t)(addr_ ## name), (uint32_t)hook_ ## name, (uint32_t **)&name ## _def);\
inlineHook((uint32_t)(addr_ ## name));

#define LOGLOTS 0

#define log(...) __android_log_print(ANDROID_LOG_INFO, "VRAPIHook", __VA_ARGS__)
#define err(...) __android_log_print(ANDROID_LOG_ERROR, "VRAPIHook", __VA_ARGS__)
