<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output encoding="UTF-16"/>

<!-- XSLT - Numbering - format= "&#x30a2;" (Japanese Aiueo DBCS) & = "&#x30a4;" (Iroha DBCS) & = "&#xff71;" -->
<!-- (Aiueo SBCS) & = "&#xff72;" (Iroha SBCS) - letter-value="alphabetic" | "traditional" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/11/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//丈且両亰亢乩乱">
			<TR><TD>  
				<TD>
					<!-- Japanese Aiueo DBCS -->
					<xsl:number format="&#x30a2;" letter-value="traditional" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>
					<!-- Iroha DBCS -->
					<xsl:number format="&#x30a4;" letter-value="alphabetic" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>
					<!-- Aiueo SBCS -->
					<xsl:number format="&#xff71;" letter-value="alphabetic" /> -
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>
					<!-- Iroha SBCS -->
					<xsl:number format="&#xff72;" letter-value="alphabetic" /> -
					<xsl:value-of select = "text()"/>							
				</TD>




			</TD></TR>  
		</xsl:for-each>  
	</TABLE>  
</xsl:template>  

</xsl:stylesheet>  
