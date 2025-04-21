# Asychrnouns Image Fetcher (aif)
**aif** is a lightweight reusable **C++ utility** for  asynchronously downloading images from the internet. It is ideal for use in real-time environments (e.g., OpenGL, OpenCV apps) where blocking the main thread is not an option 


 

<br/>
<br/>

## Features
- ✅ **Fetch images asynchronously** in a background thread
- 🔁 **Fetch one or many** images from a URL without blocking the main thread
- 🌐 **Fetch from multiple URLs** concurrently
- 🔒 Thread-safe queue and callbacks
- ⚙️ Minimal dependencies and small code

<br/>
<br/>




## Project scope
This is **not a full-featured networking/image library** — it is a **focused utility class** (named `ImageFetcher`) designed for async image downloading use-cases.


<br/>
<br/>


## Requirements


- C++17 or newer
- CPR for HTTP requests
<br/>

### Installation
Install CPR via vcpkg:
```bash
vcpkg install cpr
```

<br/>
<br/>
<br/>

## Usage

### 1. Fetch a single image

```cpp
aif::ImageFetcher fetcher;
fetcher.fetchOne("https://thispersondoesnotexist.com", [](bool success, aif::ImageFetcher::RawImage data) {
    if (success) {
        // Handle image data
    }
});
```



### 2. Fetch multiple images from the same URL
```cpp
fetcher.fetchMany(10, "https://thispersondoesnotexist.com", [](bool success, std::vector<aif::ImageFetcher::RawImage> images) {
    // images[] holds raw binary content
    // RawImage is declared as vector<unsigned char>
});
```


### 3. Fetch from a list of different URLs
```cpp
std::vector<std::string> urls = { "img1.jpg", "img2.jpg", ... };
fetcher.fetchManyFromUrls(urls, [](bool success, std::vector<aif::ImageFetcher::RawImage> imgs) {
    if(success){
        // Process fetched data
    }
});
```