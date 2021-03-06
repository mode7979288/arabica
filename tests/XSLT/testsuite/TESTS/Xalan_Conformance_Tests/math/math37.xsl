<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <!-- FileName: MATH37 -->
  <!-- Document: http://www.w3.org/TR/xpath -->
  <!-- DocVersion: 19990922 -->
  <!-- Section: 4.4 -->
  <!-- Purpose: Test of ceiling(). -->

<xsl:template match="doc">
  <out>
    <xsl:value-of select="ceiling(1)=1"/>
  </out>
</xsl:template>

</xsl:stylesheet>
