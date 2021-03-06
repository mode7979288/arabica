<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <!-- FileName: OUTPUT94 -->
  <!-- Document: http://www.w3.org/TR/xslt -->
  <!-- DocVersion: 19991116 -->
  <!-- Section: 16.1 XML Output Method-->
  <!-- Creator: David Marston -->
  <!-- Purpose: Test effect of cdata-section-elements on multiple text-node children, created by xsl:text. -->

<xsl:output method="xml" cdata-section-elements="example" encoding="UTF-8"/>

<xsl:template match="doc">
  <out>
    <example>
      <xsl:text>this is a section</xsl:text>
      <xsl:comment>Comment in between</xsl:comment>
      <xsl:text>another section</xsl:text>
    </example>
  </out>
</xsl:template>

</xsl:stylesheet>
