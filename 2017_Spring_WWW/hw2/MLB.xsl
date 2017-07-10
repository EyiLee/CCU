<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <style>
                    table {
                        border:1px solid;
                    }
                    tr, td {
                        border:1px solid;                    
                        text-align:center
                    }
                </style>
            </head>
            <body>
                <h1>Baseball</h1>
                <xsl:for-each select="mixedteams/baseball">
                <table width="720" style="margin:0px auto 100px;color:{Color}">
                    <xsl:attribute name="bgcolor">
                        <xsl:value-of select="BColor"/>
                    </xsl:attribute>
                    <xsl:attribute name="Color">
                        <xsl:value-of select="Color"/>
                    </xsl:attribute>
                    <tr>
                        <td height="160" colspan="5">
                            <xsl:value-of select="Team"/>
                        </td>
                    </tr>
                    <tr>
                        <td>Image</td>
                        <td colspan="2">star</td>
                        <td>Coach</td>
                        <td>League</td>
                    </tr>
                    <tr>
                        <td>
                            <img width="48">
                                <xsl:attribute name="src">
                                    <xsl:value-of select="Image"/>
                                </xsl:attribute>
                            </img>
                        </td>
                        <td>
                            <xsl:value-of select="star/name"/>
                        </td>
                        <td>
                            <xsl:value-of select="star/birth"/>
                        </td>
                        <td>
                            <xsl:value-of select="Coach"/>
                        </td>
                        <td>
                            <xsl:value-of select="League"/>
                        </td>                        
                    </tr>
                    <tr>
                        <td colspan="5">
                             <iframe width="720" height="480">
                                <xsl:attribute name="src">
                                    <xsl:value-of select="Video"/>
                                </xsl:attribute>
                             </iframe>
                        </td>
                    </tr>
                </table>
                </xsl:for-each>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>