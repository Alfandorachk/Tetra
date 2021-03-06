# DEPRECATED! see gentok.awk and tok.txt for newer version, since
# it was found that the scan generation was generally not great
# Takes a list of tokens for the Tetra scanner and generates a definition 
# File for them (printed to stdout)
# To test, invoke with 'awk -f mktok.awk ttoks.txt'

BEGIN {
    FS = "\N"
    RS = ""
    tvalue = 100

    print "/* A list of tokens for the Tetra scanner */"
    print "#ifndef H_TETRA_TOKENS"
    print "#define H_TETRA_TOKENS\n"
    print "#define TOK_NULL 1"
}

NF > 0 {
    print "#define TOK_" toupper($1) " " tvalue++
}

END {
    print "\n#endif"
}
