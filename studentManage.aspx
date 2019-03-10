<%@ Page Language="C#" AutoEventWireup="true" CodeFile="studentManage.aspx.cs" Inherits="studentManage" %>

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
          <td width="1200" height="40"><img src="Image/WebpageImg/subtitleImage_student.png" width="1200" height="40"></td>
        </tr>
        <tr>
          <td height="300">
              <div style="overflow-y:scroll; overflow-x:scroll; height:300px; font-family:'Microsoft YaHei'; font-size:12px">
                  <asp:GridView ID="GridView1" runat="server" BackColor="#CCFF99" AllowSorting="True"
                      AutoGenerateColumns="false" CellPadding="4" GridLines="None"
                      OnRowDeleting="GridView1_RowDeleting" OnRowEditing="GridView1_RowEditing"
                      OnRowUpdating="GridView1_RowUpdating" OnRowCancelingEdit="GridView1_RowCancelingEdit">
                      <Columns>
                          <asp:BoundField DataField="姓名" HeaderText="姓名" ReadOnly="true" />
                          <asp:BoundField DataField="班级" HeaderText="用户ID" ReadOnly="True" />
                          <asp:BoundField DataField="学号" HeaderText="用户姓名" />
                          <asp:BoundField DataField="性别" HeaderText="性别" />
                          <asp:BoundField DataField="学院" HeaderText="家庭住址" />
                          <asp:BoundField DataField="专业" HeaderText="专业" />
                          <asp:BoundField DataField="出生年月" HeaderText="出生年月" />
                          <asp:BoundField DataField="导员" HeaderText="导员" />
                          <asp:BoundField DataField="政治面貌" HeaderText="政治面貌"/>
                          <asp:BoundField DataField="民族" HeaderText="民族" />
                          <asp:BoundField DataField="就读校区" HeaderText="就读校区" />
                          <asp:CommandField HeaderText="编辑" ShowEditButton="True" />
                          <asp:CommandField HeaderText="选择" ShowSelectButton="True" />
                          <asp:CommandField HeaderText="删除" ShowDeleteButton="True" />
                      </Columns>
                      <RowStyle HorizontalAlign="Center" />
                      <HeaderStyle BackColor="#66CCFF" />
                  </asp:GridView> 
              </div>
          </td>
        </tr>
        <tr>
          <td>&nbsp;</td>
        </tr>
        <tr>
          <td>&nbsp;</td>
        </tr>
        <tr>
          <td><img src="Image/WebpageImg/tailImage.png" width="1200" height="100"></td>
        </tr>
      </table>
    </div>
    </form>
</body>
</html>
