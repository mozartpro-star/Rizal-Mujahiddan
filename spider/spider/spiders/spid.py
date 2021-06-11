import scrapy
from scrapy.spiders import CrawlSpider, Rule
from scrapy.linkextractors import LinkExtractor


class TheFriendlyNeighbourhoodSpider(CrawlSpider):
    name = 'TheFriendlyNeighbourhoodSpider'
    allowed_domains = ['en.wikipedia.org', 'upload.wikimedia.org']
    start_urls = ['https://en.wikipedia.org/wiki/Lists_of_animals']
    custom_settings = {
        'LOG_LEVEL': 'INFO'
    }
    rules = (
        Rule(LinkExtractor(), callback='parse_item', follow=True),
    )

    def parse_item(self, response):
        print('Downloaded... '+response.url)
        filename = 'storage/'+response.url.split("/")[-1] + '.html'
        print('Saving as :' + filename)
        with open(filename, 'wb') as f:
            f.write(response.body)
        return
