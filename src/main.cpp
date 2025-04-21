#include "aif/ImageFetcher.h"
#include <iostream>

void onFetchManyResult(bool status, const std::vector<aif::ImageFetcher::RawImage>& images) {
    if (!status){
		std::cout << "Failed to fetch images\n";
		return;
	}
	for(const auto& image: images) std::cout << "Image size: " << (image.size() / 1024) << "KB\n";
}



int main() {
    aif::ImageFetcher fetcher;
    
	fetcher.fetchManyFromUrls({
		"https://cdn.puzzlegarage.com/img/puzzle/e/1198_preview_r.v1.jpg",
		"https://www.teahub.io/photos/full/14-142475_daisy-flowers-wallpaper-for-android-daisy-flower.jpg",
		"https://grandgames.net/puzzle/f1200/tsveti_79.jpg",
		"https://4.bp.blogspot.com/-5COJzvei1rk/T-1gFU9OsAI/AAAAAAAACUk/-6H0gGMWTzM/s1600/Tablet+Resimleri+%2823%29.jpg"
	}, onFetchManyResult);
    std::cin.get(); // Wait for async download
    return 0;
}
