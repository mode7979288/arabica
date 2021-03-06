<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output encoding="UTF-16"/>

<!-- XSLT - Numbering - format= "&#x0410;" (Russian-Upper) & = "&#x0430;" (Russian-Lower) - letter-value="alphabetic" | "traditional" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/11/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//йцущйцшвофдлывь">
			<TR><TD>  
				<TD>
					<!-- Russian-Upper -->
					<xsl:number format="&#x0410;" letter-value="traditional" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>
					<!-- Russian-Lower -->
					<xsl:number format="&#x0430;" letter-value="alphabetic" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

			</TD></TR>  
		</xsl:for-each>  
	</TABLE>  
</xsl:template>  

</xsl:stylesheet>  
