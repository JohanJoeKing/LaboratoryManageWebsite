<%@ Page Language="C#" AutoEventWireup="true" CodeFile="equip_addEquipment.aspx.cs" Inherits="equip_addEquipment" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
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

    .tb{
        font-family:'Microsoft YaHei';
        color:#CCFFFF;
        position:relative;
        left:10px;
    }

    .textbox{
        width:230px;
        height:15px;
        font-family:'Microsoft YaHei';
        font-size:14px;
    }

    .short-text-1{
        width:50px;
        height:15px;
        font-family:'Microsoft YaHei';
        font-size:14px;
    }

    .drop{
        width:240px;
        height:25px;
        font-family:'Microsoft YaHei';
        font-size:14px;
    }

    .button{
        left:10px;
        right:5px;
        width:45px;
        font-family:'Microsoft YaHei';
        font-size:14px;
    }
</style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <table width="1200" border="0" align="center" cellpadding="0" cellspacing="0">
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
              <asp:Label ID="Label_adminName" runat="server" CssClass="account"></asp:Label>          </td>
          <td width="80" rowspan="2">
            <div align="right">
                <asp:Image ID="Image_adminImg" runat="server"/>            </div>          </td>
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
              <asp:Label ID="Label_rank" runat="server" CssClass="account"></asp:Label>
              <asp:Image ID="Image_adminRank" runat="server" />          </td>
        </tr>
        <tr>
          <td colspan="10"><img src="Image/WebpageImg/headImage.png" width="1200" height="60"></td>
        </tr>
        <tr>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
        </tr>
        <tr>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
          <td>&nbsp;</td>
        </tr>
      </table>
      <table width="1200" border="0" align="center" cellpadding="0" cellspacing="0">
        <tr>
          <td height="50" colspan="6" bgcolor="#5F687A"><table width="1000" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td width="350" height="300">
                  <div align="center" style="overflow:scroll">
                    <asp:Image ID="Image_equip" runat="server" ImageUrl="~/Image/EquipImg/default.png" />                  </div>              </td>
              <td width="650" height="300">
                  <div align="center">
                    <asp:Table ID="Table_equip" runat="server">                  </asp:Table>
                  </div>              </td>
            </tr>
            <tr>
              <td height="30">
                  <asp:TextBox ID="TextBox5" runat="server" CssClass="textbox"></asp:TextBox>
                  <div class="button">
                      <asp:Button ID="Button_choose" runat="server" CssClass="button" Text="选择" />
                  </div>
                  <div class="button">
                      <asp:Button ID="Button_upload" runat="server" CssClass="button" Text="上传" />
                  </div>
                </td>
              <td height="30">&nbsp;</td>
            </tr>
          </table></td>
        </tr>
        <tr>
          <td height="40" colspan="5"><img src="Image/WebpageImg/AddEquip_id.png" width="950" height="50">          </td>
          <td height="30"><div align="center">
              <asp:ImageButton ID="ImageButton_submit" runat="server" ImageUrl="~/Image/WebpageImg/SubmitButton.png" />
              </div></td>
        </tr>
        <tr>
          <td height="30" bgcolor="#5F687A">
              <div class="tb">
                <asp:Label ID="Label9" runat="server" Text="首设备编号"></asp:Label>
              </div>
          </td>
          <td height="50" bgcolor="#5F687A">
              <asp:TextBox ID="TextBox_headNum" runat="server" CssClass="textbox"></asp:TextBox>
          </td>
          <td height="50" bgcolor="#5F687A">
              <div class="tb">
                <asp:Label ID="Label10" runat="server" Text="尾设备编号"></asp:Label>
              </div>
          </td>
          <td height="50" bgcolor="#5F687A">
              <asp:TextBox ID="TextBox_tailNum" runat="server" CssClass="textbox"></asp:TextBox>
          </td>
          <td height="50" bgcolor="#5F687A">&nbsp;</td>
          <td height="50" bgcolor="#5F687A">&nbsp;</td>
        </tr>
        <tr>
          <td width="150" height="30" bgcolor="#7B8599">
              <div class="tb">
                <asp:Label ID="Label2" runat="server" Text="隶属单位"></asp:Label>
          </div>          </td>
          <td width="250" height="50" bgcolor="#7B8599">
          <asp:DropDownList ID="DropDownList_unit" runat="server" CssClass="drop">          </asp:DropDownList></td>
          <td width="150" height="50" bgcolor="#7B8599">
              <div class="tb">
                <asp:Label ID="Label6" runat="server" Text="投运日期"></asp:Label>
          </div>          </td>
          <td width="250" height="50" bgcolor="#7B8599">
          <asp:TextBox ID="TextBox_date" runat="server" CssClass="textbox"></asp:TextBox></td>
          <td width="150" height="50" bgcolor="#7B8599">&nbsp;</td>
          <td width="250" height="50" bgcolor="#7B8599">&nbsp;</td>
        </tr>
        <tr>
          <td width="150" height="30" bgcolor="#5F687A">
              <div class="tb">
                  <asp:Label ID="Label3" runat="server" Text="设备尺寸类型"></asp:Label>
              </div>          </td>
          <td width="250" height="50" bgcolor="#5F687A">
          <asp:DropDownList ID="DropDownList_size" runat="server" CssClass="drop">          </asp:DropDownList>          </td>
          <td width="150" height="50" bgcolor="#5F687A">
              <div class="tb">
                <asp:Label ID="Label7" runat="server" Text="顺序号"></asp:Label>
              </div>          
          </td>
          <td width="250" height="30" bgcolor="#5F687A">
             <asp:RadioButton ID="RadioButton1" runat="server" CssClass="tb" Text="单设备" />
             <asp:TextBox ID="TextBox_number" runat="server" CssClass="short-text-1"></asp:TextBox>          
          </td>
          <td width="150" height="30" bgcolor="#5F687A">&nbsp;</td>
          <td width="250" height="30" bgcolor="#5F687A">&nbsp;</td>
        </tr>
        <tr>
          <td width="150" height="50" bgcolor="#7B8599">
              <div class="tb">
                <asp:Label ID="Label4" runat="server" Text="设备类别编号"></asp:Label>
          </div>          </td>
          <td width="250" height="30" bgcolor="#7B8599">
          <asp:TextBox ID="TextBox_class" runat="server" CssClass="textbox"></asp:TextBox></td>
          <td width="150" height="30" bgcolor="#7B8599">&nbsp;</td>
          <td width="250" height="30" bgcolor="#7B8599">
              <asp:RadioButton ID="RadioButton2" runat="server" CssClass="tb" Text="多设备" />
              <asp:TextBox ID="TextBox_num1" runat="server" CssClass="short-text-1"></asp:TextBox>
            &nbsp;-
          <asp:TextBox ID="TextBox_num2" runat="server" CssClass="short-text-1"></asp:TextBox>          </td>
          <td width="150" height="30" bgcolor="#7B8599">&nbsp;</td>
          <td width="250" height="30" bgcolor="#7B8599">&nbsp;</td>
        </tr>
        <tr>
          <td width="150" height="50" bgcolor="#5F687A">
              <div class="tb">
                <asp:Label ID="Label5" runat="server" Text="型号编号"></asp:Label>
              </div>          </td>
          <td width="250" height="30" bgcolor="#5F687A">
              <asp:TextBox ID="TextBox4" runat="server" CssClass="textbox"></asp:TextBox>          </td>
          <td width="150" height="30" bgcolor="#5F687A">&nbsp;</td>
          <td width="250" height="30" bgcolor="#5F687A">&nbsp;</td>
          <td width="150" height="30" bgcolor="#5F687A">&nbsp;</td>
          <td width="250" height="30" bgcolor="#5F687A">&nbsp;</td>
        </tr>
      </table>
    </div>
    </form>
</body>
</html>
