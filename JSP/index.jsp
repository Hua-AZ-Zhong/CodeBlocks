<%@ page language="java" %>
<%@ page import="java.util.*" %>
<html>
    <head>
        <title>JSP DEMO</title>
    </head>
    <body>
        <%
            out.println("Hello, visitor!");      //嵌入java语言
            out.println("<br/>");             //换行符
            String visitorIp=getIpAddr(request);
            out.println("Your IP is " + visitorIp);
        %>
        <%out.println("<br/>");         //换行符 %>
        <%out.println("Welcome to my website!");%>
        <%! // 方法区
	    // 获取访问者IP地址
            public String getIpAddr(HttpServletRequest request) {
                String ip = request.getHeader("x-forwarded-for");
                if(ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
                    ip = request.getHeader("Proxy-Client-IP");
                }
                if(ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
                    ip = request.getHeader("WL-Proxy-Client-IP");
                }
                if(ip == null || ip.length() == 0 || "unknown".equalsIgnoreCase(ip)) {
                    ip = request.getRemoteAddr();
                }
                return ip;
            }
        %>
    </body>
</html>
