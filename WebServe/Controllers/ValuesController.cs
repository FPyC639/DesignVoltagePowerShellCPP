using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using CPPClassLib;

namespace WebServe.Controllers
{
    public class ValuesController : ApiController
    {
        [HttpGet]
        [Route("")]
        public IHttpActionResult GetValue()
        {
            var lib = new BatteryStats(); // From your CLR DLL
            var result = lib.GetDesignedCapacity(); // Assumes GetValue returns a string
            return Ok(result);
        }

    }
}
