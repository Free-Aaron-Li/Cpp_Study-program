# 简答题

任选四个，20'

---

### 1. 请简述HTTP1.0和1.1的特点及区别

- HTTP1.0
	- 一次连接一次请求响应
- HTTP1.1
	- 一次连接多次的请求响应
- 二者都是无协议状态，都是超文本传输协议，用于互联网通信

### 2. 简述HTTP请求方式GET和POST的区别

- GET
	- 将数据附在URL上，数据大小有限制（一般在2K）
	- 传输数据可见
	- 将数据和请求头一起发送服务器
	- 默认提交方式
	- 提交对于浏览器刷新和回退不影响
	- 只能使用ASCII编码
	- 提交数据能够被缓存、收藏、记录
- POST
	- 数据附在请求实体上，数据大小无限制
	- 传输数据不可见
	- 需要等待服务器响应之后才会发送数据
	- 非默认提交方式
	- 提示数据会重复提交
	- 对数据编码格式无限制
	- 提交的数据不会被缓存

### 3. 简述服务器状态码的含义

- 1xx表示请求继续
- 2xx表示服务器正常
- 3xx表示重定向
- 4xx表示客户端异常
- 5xx表示服务器异常

### 4. 列举常见的运行时异常

- 被除数为0：java.lang.ArithmeticException:/by zero
- 数组索引越界：java.lang.ArrayIndexOutOfBoundsException
- 空指针：java.lang.NullPointerException
- 数字格式错误：java.lang.NumberFormatException: For input string:"pzhu"
- 类型转换异常：java.lang.ClassCastException:java.lang.String cannot be cast to java.util.Date

### 5. 简述\<%@include/>指令和\<jsp:include/>动作元素的作用及区别

- 二者作用都是导入另外的文件
- \<%@include/>
	- 需要使用file属性导入
	- 导入的是源码文件
- \<jsp:include/>
	- 需要使用page属性
	- 导入是编译后的页面

### 6. 列举任意5个JSP内置对象及其作用

- out，用于输出内容
- request,用于处理请求相关信息
- response，用于处理响应相关信息，也可以用作存储对象
- session，用于处理绘画相关信息，也可以用作存储对象
- application，用于存储服务器级相关信息
- page，表示页面本身
- pageContext，通常用于获取页面中产生的异常
- exception，用于获取页面中产生的异常
- config，用于配置信息

### 7. 是否所有JSP都有exception对象

不是，只有当设置JSP的page指令的isErrorPage为true才有异常对象

### 8. 列举HTTPServletRequest的常见方法及作用

- getParameter()，获取请求参数的单个值
- getHeader()，获取头信息
- getParameterValues()，获取请求参数的多个值
- getSession()，获得session
- setAttribute()，存储对象到request域对象中
- getAttribute()，获取request域对象中的某个信息

### 9. 列举HTTPServletResponse的常见方法及作用

- setStatus()，设置状态码
- setContentType()，设置响应内容类型
- setDateHeader()，禁止缓存
- setHeader()，设置响应头信息
- setCookie()，写入Cookie
- getWriter()，获取输出流

### 10. 简述请求转发和重定向的区别

- 请求转发
	- 地址栏不发生变化
	- 转发范围为服务器内部
	- 请求响应次数为一次
	- 转发参数不会丢失
	- 可能造成相对路径错误
	- 可以转发到不可直接访问路径
- 重定向
	- 地址栏URL会变化
	- 重定位为任意地址
	- 可以重定向多次
	- 重定向参数会丢失
	- 重定向不会造成相对路径错误
	- 重定向不可以定向到不可直接访问路径

### 11. 列举HttpSession的常见方法及作用

- getAttribute()，获取session域对象中的值
- setAttribute()，设置session域对象中的值
- removeAttribute()，删除session域对象中的值
- invalidate，使session强制失效
- setMaxInactiveInterval()，设置session最大未激活间隔时间

### 12. 列举任意2个域对象并简述其数据存储的有效范围

- page域对象，存储范围为当前页面
- request域对象，存储范围为一次请求
- session域对象，存储范围为一次会话，从建立连接到断开连接
- application域对象，存储范围为服务器级，从服务器启动一直到关闭

### 13. 简述Servlet的生命周期各个阶段

1. 构造阶段 constructor
2. 初始化阶段 init
3. 激活阶段 service
4. 销毁阶段 destroy

### 14. 列举Filter的作用

- 对request进行处理（编码处理、自动登陆、敏感词过滤、黑白名单）
- 对response进行处理（静止缓存、允许跨域）
- 决定是否能够继续访问后续资源（权限拦截）

### 15. 简述Filter Chain中Filter的装配规则

- 配置文件中的Filter先装配，注解方式的Filter后装配
- 配置文件中的Filter按照配置顺序装配
- 注解方式中的Filter按照类名顺序装配

### 16. 列举Listener的作用

- 能够监听域对象的创建和销毁
- 能够监听域对象中属性的添加、删除和修改
- 能够监听某个对象是否被绑定到session，从session中解绑

### 17. 简述Java Web的会话技术及其区别

- 会话技术包括cookie和session
- cookie
	- 数据存储客户端
	- 存储数据可以永久保存
- session
	- 数据存储服务端
	- 存储数据随会话中断而消失

### 18. 简述JDBC注册驱动的方法及如何防止驱动重复注册

- 注册驱动的方法有：Class.forName()、DriverManager.registDriver()
- 防止驱动重复注册
	- 将注册驱动的代码放在static块中
	- 使用Class.forName()代替DriverManager.registDriver()

### 19. 简述JDBC中MySQL数据库URL的构成

格式为：jdbc:mysql://hostname:port/databasename?参数

协议、主机号、端口号、数据库名、参数

### 20. 简述Statement和PreparedStatement的区别

- PreparedStatement
	- 接口继承于Statement接口
	- 效率更高、可读性更高、可维护性更高、安全性更高
- Statement

### 21. 什么是SQL注入式攻击？应该如何避免SQL注入式攻击？

SQL注入式攻击，就是通过输入特定数据和字符来构造（或影响）SQL命令，进而欺骗服务器执行恶意的SQL命令。

避免方法：禁止输入特殊字符、对特殊字符进行转义、预编译SQL命令语句

### 22. 简述JDBC中释放连接、命令对象、结果集等资源的方法及资源释放顺序

方法：close()

释放顺序：结果集、命令对象、连接

### 23. 简述Java数据库连接池的原理和作用

原理：在程序启动时初始化一定数量的连接放入容器中，当程序需要连接时直接从容器中获取，当连接使用完毕之后，再归还到容器中。

### 24.简述注册过程中检测用户名是否可用的管理技术及流程

关键技术：Ajax

流程：前端通过JS事件触发函数，在函数中通过Ajax将用户名发送给服务器，服务器查询用户名是否被占用，然后将结果返回给Ajax的回调函数，回调函数将结果通过DOM显示在页面上

### 25. 简述验证码的作用及常见的验证码种类

作用：区分人类和计算机，防止网站服务被滥用

验证码种类：图像识别验证码、行为验证码、推理验证码

### 26. 简述对明文密码进行加密的好处及方法

好处：防止密码被泄露

方法：采用MD5、SHA等进行加密、在加密过程中可以进行加盐处理

### 27. 简述数据分页显示的方法及为何需要进行分页

方法：逻辑分页、物理分页

原因：可以减轻网页渲染负担，提高用户体验

### 28. 简述数据逻辑分页和物理分页的实现原理

- 逻辑分页
	- 将查询之后的数据通过代码分割，只保留其中需要的部分
- 物理分页
	- 将查询的时候通过limit关键词限制查询范围，只查询需要的部分

### 29. 简述三层架构的构成及各层的作用

构成：表现层、业务层、持久层

作用：

- 表现层：与用户进行交互
- 业务层：进行业务处理
- 持久层：将数据写入数据库进行持久化

### 列举可以提高数据库操作效率的措施或方法

方法：逻辑分页和物理分页

理由：提高用户体验、减少浏览器数据渲染量、加快显示速度、防止浏览器崩溃

- 利用连接池提高数据库连接效率（性能优化）
- 封装了增删改操作（返回值都是int）
- 封装查询操作（单条查询、多条查询）

### 列举可以提高项目安全性或用户体验的措施或方法

- 密码加密
- 增加验证码
- 二次验证
- 使用cookie保存必要信息
- 分页显示
- 权限拦截
- Ajax数据验证
- 进行单元测试

### 简述采用数据库连接池的优点

- 性能提升
- 资源管理
- 提供连接复用
- 支持多种数据库
- 更好地控制并发
- 提供故障恢复机制

----

# 程序设计题

### 表单

```html

<form action="todo" method="post" ">
<input type="text" name="">
<input type="password">
<input type="checkbox">

<input type="submit" value="登记">
</form>
```

### 控制层Servlet的doGet方法

```java
requst.setcharacterEncoding("utf-8");
String username=request.getParameter("username");
String age=request.getParameter("age");
if(username==null){
	
}

if("".equals(username)){
	 
}

response.sendRedirect("error.jsp"); // 重定向
request.getRequestDispatcher("error.jsp").forward(request,response); // 请求转发

request.setAttribute("username",username); // request域
request.setAttribute("age",age);
request.getSession().setAttribute("username",username); // session域
```

### 综合应用题

```java
Private String username;

varchar-String
int-Integer


extends UserInfo String

+ public 

implements UserInfoDAO

new JdbcTemplate(C3P0Util.getDataSource())

String sql="";
select * from table_name where column1=?
select * from table_name
select * from table_name where columnX like ?

insert from table_name value(?,?,?)
delete from table_name where column1 = ?
update table_name set column2=?,column3=? where column1=?
```


