<%@ Page Language="C#" AutoEventWireup="true" CodeFile="index.aspx.cs" Inherits="index" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<title>管理员界面——实验室设备管理系统</title>
<script type="text/JavaScript">
<!--
function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function MM_swapImage() { //v3.0
  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}
//-->
</script>
<style type="text/css">
    <!--
    body {
	    background-color: #385076;
    }
    -->

    .account{
        font-family:'Microsoft YaHei';
        color:#CCFFFF;
        font-size:12px;
    }

    .grid{
        font-family:'Microsoft YaHei';
        font-size:12px;
        width:650px;
        background-color:#CCFF99;
        border-bottom-color:black;
    }
</style></head>
<body onLoad="MM_preloadImages('Image/WebpageImg/EquipInfoButton2.png','Image/WebpageImg/BorrowRecordButton2.png','Image/WebpageImg/UseRateButton2.png','Image/WebpageImg/EquipRepairButton2.png','Image/WebpageImg/StudentMngButton2.png','Image/WebpageImg/SystemMngButton2.png')">
    	
        <form id="form1" runat="server">
    	
        <table width="1200" border="0" align="center" cellpadding="0" cellspacing="0">
          <tr>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="160" height="20">&nbsp;</td>
            <td width="150" height="20">
                <div align="left">
                    <asp:Label ID="Label_admin" runat="server" CssClass="account"></asp:Label>
                </div>
            </td>
            <td width="50" height="40" rowspan="2">
                <div align="right">
                    <asp:Image ID="Image1" runat="server" ImageUrl="~/Image/adminImg/male.jpg" />
                </div>
            </td>
          </tr>
          <tr>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="120" height="20">&nbsp;</td>
            <td width="160" height="20"></td>
            <td width="150" height="20">
                <div align="left">
                    <asp:Label ID="Label_rank" runat="server" CssClass="account" Text="等级："></asp:Label>
                    <asp:Image ID="Image_rank" runat="server" />
                </div>
            </td>
          </tr>
          <tr>
            <td colspan="10"><img src="Image/WebpageImg/headImage.png" width="1200" height="60"></td>
          </tr>
        </table>
		
            <table width="1200" border="0" align="center" cellpadding="0" cellspacing="0">
                <tr>
                    <td width="250">
                        <a href="equip_quickSearch.aspx" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image2','','Image/WebpageImg/EquipInfoButton2.png',1)">
                            <img src="Image/WebpageImg/EquipInfoButton.png" name="Image2" width="250" height="70" border="0">                        </a>                    </td>
                    <td width="950" rowspan="6">
                        <table width="950" border="0" align="center" cellpadding="0" cellspacing="0">
                            <tr>
						        <td width="950" height="420" style="overflow:scroll">
                                    <asp:GridView ID="GridView1" runat="server" CssClass="grid">
                                    </asp:GridView>
                   	            </td>
					        </tr>
                        </table>
                    </td>
              </tr>
              <tr>
                <td width="250"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image3','','Image/WebpageImg/BorrowRecordButton2.png',1)"><img src="Image/WebpageImg/BorrowRecordButton.png" name="Image3" width="250" height="70" border="0"></a></td>
              </tr>
              <tr>
                <td width="250"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image4','','Image/WebpageImg/UseRateButton2.png',1)"><img src="Image/WebpageImg/UseRateButton.png" name="Image4" width="250" height="70" border="0"></a></td>
              </tr>
              <tr>
                <td width="250"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image5','','Image/WebpageImg/EquipRepairButton2.png',1)"><img src="Image/WebpageImg/EquipRepairButton.png" name="Image5" width="250" height="70" border="0"></a></td>
              </tr>
              <tr>
                <td width="250"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image6','','Image/WebpageImg/StudentMngButton2.png',1)"><img src="Image/WebpageImg/StudentMngButton.png" name="Image6" width="250" height="70" border="0"></a></td>
              </tr>
              <tr>
                <td width="250"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image7','','Image/WebpageImg/SystemMngButton2.png',1)"><img src="Image/WebpageImg/SystemMngButton.png" name="Image7" width="250" height="70" border="0"></a></td>
              </tr>
        </table>
        </form>
</body>
</html>
