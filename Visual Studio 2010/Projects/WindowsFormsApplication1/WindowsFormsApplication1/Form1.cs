using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!String.IsNullOrEmpty(textName.Text) && !String.IsNullOrEmpty(textPassword.Text))
            {
                if (textName.Text == "IBM" && textPassword.Text == "IST")
                {
                    MessageBox.Show("登录成功");
                }
                else
                {
                    MessageBox.Show("用户名/密码错误");
                    textPassword.Text = "";
                }
            }
            else
            {
                MessageBox.Show("用户名或者密码不能为空");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textName.Text = "";
            textPassword.Text = "";
        }
    }
}
