<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output encoding="UTF-16"/>

<!-- XSLT - Numbering - format= "&#x0e01;" (Thai Alphabet) & = "&#x0e51;" (Thai Numbers) - letter-value="alphabetic" | "traditional" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/11/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//หสกา่ดหสากด่รีๆไ">
			<TR><TD>  
				<TD>
					<!-- Thai alphabet -->
					<xsl:number format="&#x0e01;" letter-value="traditional" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>
					<!-- Thai constants -->
					<xsl:number format="&#x0e51;" letter-value="traditional" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

			</TD></TR>  
		</xsl:for-each>  
	</TABLE>  
</xsl:template>  

</xsl:stylesheet>  
