Imports System.Text
Imports System.Threading
Imports System.IO
Imports MQTTnet
Imports MQTTnet.Client
Imports MQTTnet.Client.Options
Imports MQTTnet.Client.Connecting '' Not actually used, for now
Imports MQTTnet.Client.Disconnecting


REM Dim factory = New MqttFactory()
REM Dim mqttClient = factory.CreateMqttClient()
REM Dim options = New MqttClientOptionsBuilder().WithClientId("ClientId").WithTcpServer("ServerName", 8883).WithCredentials("UserName", "Password").WithTls().WithCleanSession().Build()
REM mqttClient.ConnectAsync(options)

Namespace My
    ' The following events are available for MyApplication:
    ' Startup: Raised when the application starts, before the startup form is created.
    ' Shutdown: Raised after all application forms are closed.  This event is not raised if the application terminates abnormally.
    ' UnhandledException: Raised if the application encounters an unhandled exception.
    ' StartupNextInstance: Raised when launching a single-instance application and the application is already active. 
    ' NetworkAvailabilityChanged: Raised when the network connection is connected or disconnected.

    ' **NEW** ApplyHighDpiMode: Raised when the application queries the HighDpiMode to set it for the application.

    ' Example:

    ' Private Sub MyApplication_ApplyHighDpiMode(sender As Object, e As ApplyHighDpiModeEventArgs) Handles Me.ApplyHighDpiMode
    '     e.HighDpiMode = HighDpiMode.PerMonitorV2
    ' End Sub
    Module Module1
        Dim mqClient As MqttClient
        Dim mqFactory As New MqttFactory
        Dim last_topic As String
        Dim last_payload As String
        Dim send_topic As String
        Dim mqtt_server, mqtt_port, mqtt_user, mqtt_password As String

        Sub mqtt_disconect()
            mqClient.DisconnectAsync().Wait()
        End Sub
        Sub mmqt_start()


        End Sub
        Function mtt_publish(topic, payload) As Boolean
            Publish(topic + payload, "20").Wait()
        End Function
        Function mqtt_connect(Client As String, Server As String, Port As String, User As String, Password As String) As Boolean
            Connect(Client, Server, Port, User, Password).Wait()
            REM Publish("sophyaispace/console", "20").Wait()
            Subscribe("sophyaispace/console/in_range_sat/#").Wait()
            mqtt_connect = True
        End Function

        Function mqtt_subscribe(Topicrx As String) As Boolean
            Subscribe(Topicrx).Wait()
        End Function
        Async Function Connect(Client As String, Server As String, Port As String, User As String, Password As String) As Task
            mqClient = CType(mqFactory.CreateMqttClient(), MqttClient)
            mqClient.UseApplicationMessageReceivedHandler(AddressOf MessageRecieved)
            mqClient.UseDisconnectedHandler(AddressOf ConnectionClosed)
            mqClient.UseConnectedHandler(AddressOf ConnectionOpened)

            Dim Options As New Options.MqttClientOptionsBuilder
            Options.WithClientId(Client).WithTcpServer(Server, Port).WithCredentials(User, Password)
            Await mqClient.ConnectAsync(Options.Build).ConfigureAwait(False)
        End Function

        Async Function Publish(Topic As String, Payload As String) As Task
            Await mqClient.PublishAsync(Topic, Payload).ConfigureAwait(False)
        End Function

        Async Function Subscribe(Topic As String) As Task
            Await mqClient.SubscribeAsync(Topic).ConfigureAwait(False)
        End Function

        Private Sub MessageRecieved(e As MqttApplicationMessageReceivedEventArgs)
            last_topic = e.ApplicationMessage.Topic
            last_payload = Text.Encoding.UTF8.GetString(e.ApplicationMessage.Payload)
        End Sub

        Public Function get_last_topic() As String
            get_last_topic = last_topic
        End Function
        Public Function get_last_payload() As String
            get_last_payload = last_payload
        End Function
        Private Sub ConnectionClosed(e As Disconnecting.MqttClientDisconnectedEventArgs)
            MessageBox.Show("Connection closed.")
        End Sub

        Private Sub ConnectionOpened(e As Connecting.MqttClientConnectedEventArgs)
            MessageBox.Show("Connection opened.")
        End Sub
    End Module
    Partial Friend Class MyApplication

    End Class
End Namespace
