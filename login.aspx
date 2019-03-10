<%@ Page Language="C#" AutoEventWireup="true" CodeFile="login.aspx.cs" Inherits="login" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<title>登录界面——实验室设备管理系统</title>
<style type="text/css">
    <!--
    body {
	    background-color: #385076;
    }
    -->

    .tb{
        width:300px;
        height:25px;
        font-family:'Microsoft YaHei';
        font-size:12px;
    }

    .wrd{
        font-family:'Microsoft YaHei';
        font-size:18px;
        color:#C3C3C3;
    }
</style>
</head>
<body>
	<div>
		<table width="1200" border="0" align="center" cellpadding="0" cellspacing="0">
			<tr>
				<td width="1200" height="60"><img src="Image/WebpageImg/headImage.png" width="1200" height="60">				</td>
			</tr>
		</table>
	</div>
    <form id="form1" runat="server">
    <div>
      <table width="800" border="0" align="center" cellpadding="0" cellspacing="0">
        <tr>
          <td width="800" height="100">&nbsp;</td>
        </tr>
        <tr>
          <td><table width="500" border="0" align="center" cellpadding="0" cellspacing="0">
            <tr>
              <td bgcolor="#5F687A"><img src="Image/WebpageImg/loginHead.png" width="500" height="30"></td>
            </tr>
            <tr>
              <td bgcolor="#5F687A"><table width="480" border="0" align="center" cellpadding="0" cellspacing="0">
                  <tr>
                    <td height="40">&nbsp;</td>
                    <td height="40">&nbsp;</td>
                  </tr>
                  <tr>
                    <td width="100" height="40"><div align="center">
                        <asp:Label ID="Label_account" runat="server" CssClass="wrd" Text="账号"></asp:Label>
                    </div></td>
                    <td width="380" height="40"><asp:TextBox ID="Text_account" runat="server" CssClass="tb"></asp:TextBox>
                    </td>
                  </tr>
                  <tr>
                    <td width="100" height="40"><div align="center">
                        <asp:Label ID="Label_pwd" runat="server" CssClass="wrd" Text="密码"></asp:Label>
                    </div></td>
                    <td width="380" height="40"><asp:TextBox ID="Text_pwd" runat="server" CssClass="tb" TextMode="Password"></asp:TextBox>
                    </td>
                  </tr>
              </table></td>
            </tr>
            <tr>
              <td height="50" bgcolor="#5F687A"><div align="center">
                  <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="~/Image/WebpageImg/loginButton.png" OnClick="ImageButton1_Click" />          
              </div></td>
            </tr>
            <tr>
              <td height="30" bgcolor="#5F687A"><img src="Image/WebpageImg/loginHead.png" width="500" height="30"></td>
            </tr>
          </table></td>
        </tr>
        <tr>
          <td>&nbsp;</td>
        </tr>
      </table>
    </div>
    </form>
</body>
</html>
