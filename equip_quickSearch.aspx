<%@ Page Language="C#" AutoEventWireup="true" CodeFile="equip_quickSearch.aspx.cs" Inherits="equip_quickSearch" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<title>快速查询设备——实验室设备管理系统</title>
<style type="text/css">
    <!--
    body {
	    background-color: #385076;
    }
    -->
    .no_border{
	    border: 0;
	    width: 340px;
	    height: 25px;
	    font-size: 14px;
	    font-family: 'Microsoft YaHei';
	    position: relative;
	    top: 0px;
	    left: 10px;
	    outline: none;
    }

    .tb-font{
        font-family:'Microsoft YaHei';
        color:#CCFFFF;
        position:relative;
        left:10px;
    }

    .auto-style1 {
        font-family:'Microsoft YaHei';
        color:#CCFFFF;
    }

    .account{
        font-family:'Microsoft YaHei';
        color:#CCFFFF;
        font-size:12px;
    }
</style>
<script type="text/JavaScript">
<!--
function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}

function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
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
</head>
<body onLoad="MM_preloadImages('Image/WebpageImg/EquipDivButton12.png','Image/WebpageImg/EquipDivButton22.png','Image/WebpageImg/EquipDivButton32.png','Image/WebpageImg/EquipDivButton42.png','Image/WebpageImg/EquipDivButton52.png','Image/WebpageImg/EquipDivButton62.png')">
    <form id="form1" runat="server">
    <table width="1200" border="0" align="center" cellspacing="0">
        <tr>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="160">
            <div align="left">
                <asp:Label ID="Label_admin" runat="server" CssClass="account"></asp:Label>
            </div>          </td>
          <td width="80" rowspan="2">
          <div align="right">
                <asp:Image ID="Image1" runat="server" ImageUrl="~/Image/adminImg/male.jpg" />          </div>          </td>
        </tr>
        <tr>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="120">&nbsp;</td>
          <td width="160">
            <div align="left">
                <asp:Label ID="Label_rank" runat="server" CssClass="account" Text="等级："></asp:Label>
                <asp:Image ID="Image_rank" runat="server" />
            </div>          </td>
        </tr>
        <tr>
          <td colspan="10"><img src="Image/WebpageImg/headImage.png" width="1200" height="60"></td>
        </tr>
        <tr>
          <td width="120" height="40"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image3','','Image/WebpageImg/EquipDivButton12.png',1)"><img src="Image/WebpageImg/EquipDivButton11.png" name="Image3" width="120" height="40" border="0"></a></td>
          <td width="120" height="40"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image4','','Image/WebpageImg/EquipDivButton22.png',1)"><img src="Image/WebpageImg/EquipDivButton21.png" name="Image4" width="120" height="40" border="0"></a></td>
          <td width="120" height="40"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image5','','Image/WebpageImg/EquipDivButton32.png',1)"><img src="Image/WebpageImg/EquipDivButton31.png" name="Image5" width="120" height="40" border="0"></a></td>
          <td width="120" height="40"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image6','','Image/WebpageImg/EquipDivButton42.png',1)"><img src="Image/WebpageImg/EquipDivButton41.png" name="Image6" width="120" height="40" border="0"></a></td>
          <td width="120" height="40"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image7','','Image/WebpageImg/EquipDivButton52.png',1)"><img src="Image/WebpageImg/EquipDivButton51.png" name="Image7" width="120" height="40" border="0"></a></td>
          <td width="120" height="40"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image8','','Image/WebpageImg/EquipDivButton62.png',1)"><img src="Image/WebpageImg/EquipDivButton61.png" name="Image8" width="120" height="40" border="0"></a></td>
          <td width="120" height="40"><img src="Image/WebpageImg/EquipDivButton1.png" width="120" height="40"></td>
          <td width="120" height="40"><img src="Image/WebpageImg/EquipDivButton1.png" width="120" height="40"></td>
          <td height="40" colspan="2"><img src="Image/WebpageImg/EquipDivButton3.png" width="240" height="40"></td>
        </tr>
        <tr>
          <td colspan="10">&nbsp;</td>
        </tr>
    </table>
      <table width="1200" border="1" align="center" cellpadding="0" cellspacing="0" bordercolor="#CCCCCC">
        <tr>
          <td width="350" colspan="2" rowspan="8" bgcolor="#4682B4"><div align="center" style="overflow-x:scroll;overflow-y:scroll;height:320px;width:500px;">
            <asp:Image ID="Img_equip" runat="server" ImageUrl="~/Image/EquipImg/default_300_200.png" />
          </div></td>
          <td width="150" height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label1" runat="server" CssClass="tb-font" Text="设备名称："></asp:Label>
          </div></td>
          <td width="550" height="40" bgcolor="#4682B4">
          <asp:Label ID="Label_equip_name" runat="server" CssClass="tb-font"></asp:Label></td>
        </tr>
        <tr>
          <td width="150" height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label2" runat="server" CssClass="tb-font" Text="类型："></asp:Label>
          </div></td>
          <td width="550" height="40" bgcolor="#5F9EA0">
          <asp:Label ID="Label_equip_class" runat="server" CssClass="tb-font"></asp:Label></td>
        </tr>
        <tr>
          <td width="150" height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label9" runat="server" CssClass="tb-font" Text="型号："></asp:Label>
          </div></td>
          <td width="550" height="40" bgcolor="#4682B4">
              <asp:Label ID="Label_equip_type" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td width="150" height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label10" runat="server" CssClass="tb-font" Text="生产商："></asp:Label>
          </div></td>
          <td width="550" height="40" bgcolor="#5F9EA0">
              <asp:Label ID="Label_equip_producer" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td width="150" height="40" bgcolor="#4682B4" class="auto-style1"><div align="center">
            <asp:Label ID="Label11" runat="server" CssClass="tb-font" Text="生产日期："></asp:Label>
          </div></td>
          <td width="550" height="40" bgcolor="#4682B4" class="auto-style1">
          <asp:Label ID="Label_produce_date" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label12" runat="server" CssClass="tb-font" Text="保质期："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0">
              <asp:Label ID="Label_guarantee_period" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label13" runat="server" CssClass="tb-font" Text="购买日期："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4">
              <asp:Label ID="Label_purchase_date" runat="server" CssClass="tb-font"></asp:Label>          </td>
        </tr>
        <tr>
          <td height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label14" runat="server" CssClass="tb-font" Text="投运日期："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0">
              <asp:Label ID="Label_use_date" runat="server" CssClass="tb-font"></asp:Label>          </td>
        </tr>
        <tr>
          <td height="40" bgcolor="#4682B4"><div align="center">
            <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="~/Image/WebpageImg/SearchButtonImg.png" OnClick="ImageButton1_Click" />
          </div></td>
          <td height="40" bgcolor="#4682B4"><asp:TextBox ID="Text_equip_id" runat="server" AutoPostBack="true" CssClass="no_border" OnTextChanged="TextBox1_TextChanged"></asp:TextBox></td>
          <td height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label15" runat="server" CssClass="tb-font" Text="供应单位："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4">
              <asp:Label ID="Label_supply_unit" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label3" runat="server" CssClass="tb-font" Text="单价："></asp:Label>
          </div></td>
          <td bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label_equip_price" runat="server" CssClass="tb-font"></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label16" runat="server" CssClass="tb-font" Text="采购单位："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0">
              <asp:Label ID="Label_purchase_unit" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label4" runat="server" CssClass="tb-font" Text="设备状态："></asp:Label>
          </div></td>
          <td bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label_equip_status" runat="server" CssClass="tb-font"></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label17" runat="server" CssClass="tb-font" Text="使用单位："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4">
              <asp:Label ID="Label_use_unit" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td colspan="2" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label19" runat="server" CssClass="tb-font" Text="实习项目"></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label18" runat="server" CssClass="tb-font" Text="隶属实验室："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0">
              <asp:Label ID="Label_lab" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td colspan="2" rowspan="2" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label_equip_project" runat="server" CssClass="tb-font"></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label20" runat="server" CssClass="tb-font" Text="项目内用途："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4">
              <asp:Label ID="Label_function" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label21" runat="server" CssClass="tb-font" Text="计量单位："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0">
              <asp:Label ID="Label_count_unit" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td colspan="2" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label5" runat="server" CssClass="tb-font" Text="备 注"></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label22" runat="server" CssClass="tb-font" Text="附属设备数量："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4">
              <asp:Label ID="Label_consist" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td colspan="2" rowspan="3" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label_equip_note" runat="server" CssClass="tb-font"></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0"><div align="center">
            <asp:Label ID="Label23" runat="server" CssClass="tb-font" Text="存放位置："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#5F9EA0">
              <asp:Label ID="Label_store" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td height="40" bgcolor="#4682B4"><div align="center">
            <asp:Label ID="Label24" runat="server" CssClass="tb-font" Text="分管人员："></asp:Label>
          </div></td>
          <td height="40" bgcolor="#4682B4">
              <asp:Label ID="Label_teacher" runat="server" CssClass="tb-font"></asp:Label>            </td>
        </tr>
        <tr>
          <td height="40" bgcolor="#5F9EA0">&nbsp;</td>
          <td height="40" bgcolor="#5F9EA0">&nbsp;</td>
        </tr>
        <tr>
          <td height="40" colspan="4"><img src="Image/WebpageImg/tailImage.png" width="1200" height="100"></td>
        </tr>
      </table>
    </form>
</body>
</html>
