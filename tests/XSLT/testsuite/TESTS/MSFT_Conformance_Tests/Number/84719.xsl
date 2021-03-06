<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output encoding="UTF-16"/>

<!-- XSLT - Numbering - format= "&#xc77c;" (Korean Decimal 2) & = "&#xd558;" (Korean 99) -->
<!--  & = "&#xac00;" (Korean Ganada) & = "&#x3131;" (Korean Chosung) & = "&#x4e01;" (Korean Decimal) -->
<!-- letter-value="alphabetic" | "traditional" - lang="ko" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/11/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//하홏흄료">
			<TR><TD>  
				<TD>
					<!-- Korean Decimal 2 -->
					<xsl:number format="&#xc77c;" letter-value="traditional" /> *					
					<xsl:value-of select = "text()"/>
				</TD>

				<!-- visual separator -->
				<TD>|----|	</TD>
		
				<TD>
					<!-- Korean 99 -->
					<xsl:number format="&#xd558;" letter-value="alphabetic" /> *
					<xsl:value-of select = "text()"/>							
				</TD>

				<!-- visual separator -->
				<TD>|----|	</TD>

				<TD>
					<!-- Korean Ganada -->
					<xsl:number format="&#xac00;" letter-value="alphabetic" /> *
					<xsl:value-of select = "text()"/>							
				</TD>

				<!-- visual separator -->
				<TD>|----|	</TD>

				<TD>
					<!-- Korean Chosung -->
					<xsl:number format="&#x3131;" letter-value="alphabetic" /> *
					<xsl:value-of select = "text()"/>							
				</TD>

				<TD>|----|	</TD>
				
				<TD>
					<!-- Korean Decimal -->
					<xsl:number format="&#x4e01;" lang="ko" letter-value="alphabetic" /> *
					<xsl:value-of select = "text()"/>							
				</TD>

			</TD></TR>  
		</xsl:for-each>  
	</TABLE>  
</xsl:template>  

</xsl:stylesheet>  

