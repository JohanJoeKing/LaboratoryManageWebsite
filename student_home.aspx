<%@ Page Language="C#" AutoEventWireup="true" CodeFile="student_home.aspx.cs" Inherits="student_home" %>

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
</style></head>
<body>
    <form id="form1" runat="server">
    <div>
      <table width="1200" border="0" align="center" cellpadding="0" cellspacing="0">
        <tr>
          <td><img src="Image/WebpageImg/headImage.png" width="1200" height="60"></td>
        </tr>
        <tr>
          <td><img src="Image/WebpageImg/subtitleImage_student.png" width="1200" height="40"></td>
        </tr>
        <tr>
          <td>
              <div style="overflow-y:scroll; overflow-x:scroll; height:300px; font-family:'Microsoft YaHei'; font-size:12px">
                  <asp:Table ID="Table1" runat="server">
                  </asp:Table>
              </div>
          </td>
        </tr>
        <tr>
          <td>&nbsp;</td>
        </tr>
      </table>
    </div>
    </form>
</body>
</html>
