using Microsoft.AspNetCore.Mvc;

namespace RemoteWebApi.Controllers;

[ApiController]
[Route("[controller]")]
public class RemoteController : ControllerBase
{

    //[HttpGet(Name = "volumeUp")]
    [HttpGet("/volup")]
    public string GetVolumeUp()
    {
        Console.WriteLine($"GET GetVolumeUp(): {System.DateTime.Now.ToString("HH:mm:ss")}");
        return "Volume  Up";
    }

    [HttpGet("/voldown")]
    public string GetVolumeDown()
    {
        Console.WriteLine($"GET GetVolumeDown(): {System.DateTime.Now.ToString("HH:mm:ss")}");
        return "Volume Dowm";
    }
}
