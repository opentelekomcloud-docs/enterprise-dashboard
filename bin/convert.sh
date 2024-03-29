#!/bin/bash

# to initially convert a .docx format file, use this pandoc call:

pandoc -o full.rst \
       --wrap=preserve \
       -f docx \
       -t rst \
       --top-level-division=chapter \
       --extract-media=. \
       edb-umn-2023-03-04.docx

exit 0

# After this process, you have to manually
#
#  - check the results
#  - fix tables
#  - slice the one single document into smaller, digestable pieces

# For reference, here are the pandoc options:

pandoc [OPTIONS] [FILES]
  -f FORMAT, -r FORMAT  --from=FORMAT, --read=FORMAT                    
  -t FORMAT, -w FORMAT  --to=FORMAT, --write=FORMAT                     
  -o FILE               --output=FILE                                   
                        --data-dir=DIRECTORY                            
  -M KEY[:VALUE]        --metadata=KEY[:VALUE]                          
                        --metadata-file=FILE                            
  -d FILE               --defaults=FILE                                 
                        --file-scope                                    
                        --sandbox                                       
  -s                    --standalone                                    
                        --template=FILE                                 
  -V KEY[:VALUE]        --variable=KEY[:VALUE]                          
                        --wrap=auto|none|preserve                       
                        --ascii                                         
                        --toc, --table-of-contents                      
                        --toc-depth=NUMBER                              
  -N                    --number-sections                               
                        --number-offset=NUMBERS                         
                        --top-level-division=section|chapter|part       
                        --extract-media=PATH                            
                        --resource-path=SEARCHPATH                      
  -H FILE               --include-in-header=FILE                        
  -B FILE               --include-before-body=FILE                      
  -A FILE               --include-after-body=FILE                       
                        --no-highlight                                  
                        --highlight-style=STYLE|FILE                    
                        --syntax-definition=FILE                        
                        --dpi=NUMBER                                    
                        --eol=crlf|lf|native                            
                        --columns=NUMBER                                
  -p                    --preserve-tabs                                 
                        --tab-stop=NUMBER                               
                        --pdf-engine=PROGRAM                            
                        --pdf-engine-opt=STRING                         
                        --reference-doc=FILE                            
                        --self-contained                                
                        --request-header=NAME:VALUE                     
                        --no-check-certificate                          
                        --abbreviations=FILE                            
                        --indented-code-classes=STRING                  
                        --default-image-extension=extension             
  -F PROGRAM            --filter=PROGRAM                                
  -L SCRIPTPATH         --lua-filter=SCRIPTPATH                         
                        --shift-heading-level-by=NUMBER                 
                        --base-header-level=NUMBER                      
                        --strip-empty-paragraphs                        
                        --track-changes=accept|reject|all               
                        --strip-comments                                
                        --reference-links                               
                        --reference-location=block|section|document     
                        --atx-headers                                   
                        --markdown-headings=setext|atx                  
                        --listings                                      
  -i                    --incremental                                   
                        --slide-level=NUMBER                            
                        --section-divs                                  
                        --html-q-tags                                   
                        --email-obfuscation=none|javascript|references  
                        --id-prefix=STRING                              
  -T STRING             --title-prefix=STRING                           
  -c URL                --css=URL                                       
                        --epub-subdirectory=DIRNAME                     
                        --epub-cover-image=FILE                         
                        --epub-metadata=FILE                            
                        --epub-embed-font=FILE                          
                        --epub-chapter-level=NUMBER                     
                        --ipynb-output=all|none|best                    
  -C                    --citeproc                                      
                        --bibliography=FILE                             
                        --csl=FILE                                      
                        --citation-abbreviations=FILE                   
                        --natbib                                        
                        --biblatex                                      
                        --mathml                                        
                        --webtex[=URL]                                  
                        --mathjax[=URL]                                 
                        --katex[=URL]                                   
                        --gladtex                                       
                        --trace                                         
                        --dump-args                                     
                        --ignore-args                                   
                        --verbose                                       
                        --quiet                                         
                        --fail-if-warnings                              
                        --log=FILE                                      
                        --bash-completion                               
                        --list-input-formats                            
                        --list-output-formats                           
                        --list-extensions[=FORMAT]                      
                        --list-highlight-languages                      
                        --list-highlight-styles                         
  -D FORMAT             --print-default-template=FORMAT                 
                        --print-default-data-file=FILE                  
                        --print-highlight-style=STYLE|FILE              
  -v                    --version                                       
  -h                    --help                                          
