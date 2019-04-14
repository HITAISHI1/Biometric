namespace Fingerprint2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {

            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.start_btn = new System.Windows.Forms.Button();
            this.input_srl = new System.IO.Ports.SerialPort(this.components);
            this.exp_txt = new System.Windows.Forms.TextBox();
            this.stop_btn = new System.Windows.Forms.Button();
            this.input_txt = new System.Windows.Forms.TextBox();
            this.enroll_btn = new System.Windows.Forms.Button();
            this.search_btn = new System.Windows.Forms.Button();
            this.enroll_id_btn = new System.Windows.Forms.Button();
            this.input_lbl = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // start_btn
            // 
            this.start_btn.Location = new System.Drawing.Point(12, 12);
            this.start_btn.Name = "start_btn";
            this.start_btn.Size = new System.Drawing.Size(75, 57);
            this.start_btn.TabIndex = 0;
            this.start_btn.Text = "Start";
            this.start_btn.UseVisualStyleBackColor = true;
            this.start_btn.Click += new System.EventHandler(this.start_btn_Click);
            // 
            // input_srl
            // 
            this.input_srl.PortName = "COM7";
            // 
            // exp_txt
            // 
            this.exp_txt.Location = new System.Drawing.Point(93, 12);
            this.exp_txt.Multiline = true;
            this.exp_txt.Name = "exp_txt";
            this.exp_txt.ReadOnly = true;
            this.exp_txt.Size = new System.Drawing.Size(516, 190);
            this.exp_txt.TabIndex = 1;
            // 
            // stop_btn
            // 
            this.stop_btn.Location = new System.Drawing.Point(12, 136);
            this.stop_btn.Name = "stop_btn";
            this.stop_btn.Size = new System.Drawing.Size(75, 57);
            this.stop_btn.TabIndex = 2;
            this.stop_btn.Text = "Stop";
            this.stop_btn.UseVisualStyleBackColor = true;
            this.stop_btn.Click += new System.EventHandler(this.stop_btn_Click);
            // 
            // input_txt
            // 
            this.input_txt.Enabled = false;
            this.input_txt.Location = new System.Drawing.Point(615, 45);
            this.input_txt.Name = "input_txt";
            this.input_txt.Size = new System.Drawing.Size(180, 22);
            this.input_txt.TabIndex = 3;
            // 
            // enroll_btn
            // 
            this.enroll_btn.Location = new System.Drawing.Point(615, 73);
            this.enroll_btn.Name = "enroll_btn";
            this.enroll_btn.Size = new System.Drawing.Size(88, 57);
            this.enroll_btn.TabIndex = 4;
            this.enroll_btn.Text = "Enroll";
            this.enroll_btn.UseVisualStyleBackColor = true;
            this.enroll_btn.Click += new System.EventHandler(this.enroll_btn_Click);
            // 
            // search_btn
            // 
            this.search_btn.Location = new System.Drawing.Point(615, 136);
            this.search_btn.Name = "search_btn";
            this.search_btn.Size = new System.Drawing.Size(180, 66);
            this.search_btn.TabIndex = 5;
            this.search_btn.Text = "Search";
            this.search_btn.UseVisualStyleBackColor = true;
            this.search_btn.Click += new System.EventHandler(this.search_btn_Click);
            // 
            // enroll_id_btn
            // 
            this.enroll_id_btn.Enabled = false;
            this.enroll_id_btn.Location = new System.Drawing.Point(709, 73);
            this.enroll_id_btn.Name = "enroll_id_btn";
            this.enroll_id_btn.Size = new System.Drawing.Size(88, 57);
            this.enroll_id_btn.TabIndex = 6;
            this.enroll_id_btn.Text = "Enroll Id";
            this.enroll_id_btn.UseVisualStyleBackColor = true;
            this.enroll_id_btn.Click += new System.EventHandler(this.enroll_id_btn_Click);
            // 
            // input_lbl
            // 
            this.input_lbl.AutoSize = true;
            this.input_lbl.Location = new System.Drawing.Point(615, 25);
            this.input_lbl.Name = "input_lbl";
            this.input_lbl.Size = new System.Drawing.Size(133, 17);
            this.input_lbl.TabIndex = 7;
            this.input_lbl.Text = "Input FIngerPrint ID:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(810, 214);
            this.Controls.Add(this.input_lbl);
            this.Controls.Add(this.enroll_id_btn);
            this.Controls.Add(this.search_btn);
            this.Controls.Add(this.enroll_btn);
            this.Controls.Add(this.input_txt);
            this.Controls.Add(this.stop_btn);
            this.Controls.Add(this.exp_txt);
            this.Controls.Add(this.start_btn);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Biometric System";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button start_btn;
        private System.IO.Ports.SerialPort input_srl;
        private System.Windows.Forms.TextBox exp_txt;
        private System.Windows.Forms.Button stop_btn;
        private System.Windows.Forms.TextBox input_txt;
        private System.Windows.Forms.Button enroll_btn;
        private System.Windows.Forms.Button search_btn;
        private System.Windows.Forms.Button enroll_id_btn;
        private System.Windows.Forms.Label input_lbl;
    }
}

