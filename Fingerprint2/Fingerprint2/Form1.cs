using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;
namespace Fingerprint2
{
    public partial class Form1 : Form
    {
        String incomingData;
  //      private static object lockObject = new object();
        delegate void StringArgReturningVoidDelegate(string text);

        private void SetText(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (exp_txt.InvokeRequired)
            {
                StringArgReturningVoidDelegate d = new StringArgReturningVoidDelegate(SetText);
                this.Invoke(d, new object[] { text });
            }
            else
            {

                if (exp_txt.TextLength >= exp_txt.MaxLength)
                    exp_txt.Text = "";

                    exp_txt.Text += text;

                    exp_txt.SelectionStart = exp_txt.Text.Length;
                    exp_txt.ScrollToCaret();
            }
        }
        public Form1()
        {
            InitializeComponent();
            
        }
        private void port_DataReceived(object sender,
                                 SerialDataReceivedEventArgs e)
        {
            // Show all the incoming data in the port's buffer in the output window
            SetText("\n" + input_srl.ReadLine());
        }
        private void start_btn_Click(object sender, EventArgs e)
        {
            if (input_srl.IsOpen == true)
                input_srl.Close();
            input_srl.Open();
            input_srl.DataReceived += new SerialDataReceivedEventHandler(port_DataReceived);   

        }

        private void stop_btn_Click(object sender, EventArgs e)
        {
            input_srl.Close();
        }



        private void enroll_btn_Click(object sender, EventArgs e)
        {
            input_srl.WriteLine("1");
            enroll_id_btn.Enabled = true;
            input_txt.Enabled = true;
        }

        private void search_btn_Click(object sender, EventArgs e)
        {
            input_srl.WriteLine("2");
        }

        private void enroll_id_btn_Click(object sender, EventArgs e)
        {
            if (input_txt.Text != "")
            {
                input_srl.WriteLine(input_txt.Text);
                input_txt.Text = "";

                enroll_id_btn.Enabled = false;
                input_txt.Enabled = false;
            }
            else
            {
                MessageBox.Show("Enter Id!!!!");
            }
        }
    }
}
