<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:template match="/">
        <xsl:for-each select="//book[@style='textbook']">
            <author firstName="{*}"></author>
        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>
