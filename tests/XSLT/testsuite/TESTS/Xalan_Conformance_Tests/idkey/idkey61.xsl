<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <!-- FileName: idkey61 -->
  <!-- Document: http://www.w3.org/TR/xpath -->
  <!-- DocVersion: 19991116 -->
  <!-- Section: 4.1 -->
  <!-- Creator: David Marston -->
  <!-- Purpose: Test for count() of id(), multiple values. -->

<xsl:output method="xml" encoding="UTF-8" indent="no"/>

<xsl:template match="/">
  <out>
    <xsl:value-of select="count(id('d b c k'))"/>
  </out>
</xsl:template>

</xsl:stylesheet>