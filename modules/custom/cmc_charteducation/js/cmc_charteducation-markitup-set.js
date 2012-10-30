// ----------------------------------------------------------------------------
// markItUp!
// ----------------------------------------------------------------------------
// Copied from  http://markitup.jaysalvat.com/
// ----------------------------------------------------------------------------
// CMC Tokens 
var cmc_education_tokens = {
  nameSpace:'cmc_education',

  markupSet:  [   
    {name:'headline item', className:'cmc_charteducation-headline', 
      openWith: '<item type="headline">', closeWith:'</item>' + "\n"},
    {name:'text item', className:'cmc_charteducation-text', 
      openWith: '<item type="text">', closeWith:'</item>' + "\n"},
    {name:'caption item', className:'cmc_charteducation-caption', 
      openWith: '<item type="caption">', closeWith:'</item>' + "\n"},
    {name:'image item', className:'cmc_charteducation-image', 
      openWith: '<item type="image">', closeWith:'</item>' + "\n"},
    {name:'dotted line item', className:'cmc_charteducation-dotted-line', 
        openWith: '<item type="dotted-line"> </item>', closeWith: "\n"},
    {name:'bold', className:'cmc_charteducation-bold', 
        openWith: '<b>', closeWith: "</b> "},
    {name:'italics', className:'cmc_charteducation-italics', 
          openWith: '<i>', closeWith: "</i> "},
    {name:'underline', className:'cmc_charteducation-underline', 
        openWith: '<u>', closeWith: "</u> "},
  ]
}